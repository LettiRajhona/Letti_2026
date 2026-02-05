#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

void lock_first_half(int file, off_t filesize) {
    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = filesize / 2;

    printf("Child locking first half...\n");
    fcntl(file, F_SETLKW, &lock);
}

void unlock_file(int fd, off_t filesize) {
    struct flock lock;

    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = filesize / 2;

    fcntl(fd, F_SETLK, &lock);
}

int main() {
    const char* child_msg  = "Child process is writing...\n";
    const char* parent_msg = "Parent process is writing...\n";

    int fd = open("data.txt", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644);
    if (fd < 0) { 
        perror("open"); 
        exit(1); 
    }

    for (int i = 0; i < 20; i++)
        write(fd, "0123456789\n", 11);
    close(fd);

    fd = open("data.txt", O_WRONLY | O_APPEND, 0644);
    if (fd < 0) { 
        perror("open"); 
        exit(1); 
    }

    off_t filesize = lseek(fd, 0, SEEK_END);

    pid_t pid = fork();
    if (pid < 0) { 
        perror("fork"); 
        exit(1); 
    }

    if (pid == 0) {
        lock_first_half(fd, filesize);

        for (int i = 0; i < 10; i++) {
            write(fd, child_msg, strlen(child_msg));
            sleep(1);
        }

        unlock_file(fd, filesize);
        close(fd);

        exit(0);
    } else {
        for (int i = 0; i < 10; i++) {
            write(fd, parent_msg, strlen(parent_msg));
            sleep(1);
        }

        wait(NULL);
        close(fd);
    }

    return 0;
}