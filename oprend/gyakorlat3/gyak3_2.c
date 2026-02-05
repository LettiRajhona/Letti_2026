#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    int status;
    pid_t pid = fork();

    if (pid > 0) {
        pid_t finished_child = wait(&status);

        printf("Child with process ID %d finished running.\n", finished_child);
        
        if (WIFEXITED(status)) {
            printf("Child exited with status %d.\n", WEXITSTATUS(status));
        } else {
            printf("Child did not exit normally.\n");
        }
    } else if (pid == 0) {
        printf("Child with process ID %d is running.\n", getpid());
        
        sleep(5);
        exit(7);
    } else {
        perror("Fork failed");
        exit(1);
    }

    return 0;
}