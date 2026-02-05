#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

void lock_file(int fd) {
    struct flock lock;
    lock.l_type = F_WRLCK;     
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;           

    fcntl(fd, F_SETLKW, &lock);  
}

void unlock_file(int fd) {
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    fcntl(fd, F_SETLK, &lock);
}

int main() {
    int file = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644);
    if (file < 0) {
        perror("Failed to open file");
        exit(1);
    }

    for (int i = 0; i < 4; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            lock_file(file);

            for (int j = 0; j < 5; j++) {
                char buffer[100];
                snprintf(buffer, sizeof(buffer), "Process %d writes in line %d\n", i, j + 1);

                write(file, buffer, strlen(buffer));
                usleep(100000);
            }

            unlock_file(file);
            close(file);

            exit(0);
        }
    }

    for (int i = 0; i < 4; i++) {
        wait(NULL);
    }

    close(file);
    return 0;
}