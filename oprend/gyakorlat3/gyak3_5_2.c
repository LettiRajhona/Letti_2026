#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <sys/file.h>

int main() {
    pid_t pid = fork();

    const char* child_msg  = "Child process writing to file.\n";
    const char* parent_msg = "Parent process writing to file.\n";

    int file = open("data2.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (pid > 0) {
        flock(file, LOCK_EX);

        for (int i = 0; i < strlen(parent_msg); i++) {
            write(file, &parent_msg[i], 1);
            usleep(100000); 
        }

        flock(file, LOCK_UN); 
        wait(NULL); 
    } else if (pid == 0) {
        flock(file, LOCK_EX);

        for (int i = 0; i < strlen(child_msg); i++) {
            write(file, &child_msg[i], 1);
            usleep(150000); 
        }

        flock(file, LOCK_UN);
    } else {
        perror("Fork failed");
        exit(1);
    }

    close(file);

    return 0;
}
