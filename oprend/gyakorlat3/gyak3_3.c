#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define CHILD_COUNT 3

int main() {
    int status;
    pid_t pid;

    srand(time(NULL));

    for (int i = 0; i < CHILD_COUNT; i++) {
        pid = fork();

        if (pid == 0) {
            srand(getpid());

            int sleepTime = rand() % 10 + 1;
            int exitCode  = rand() % 256;       

            sleep(sleepTime);
            exit(exitCode);
        } else {
            perror("Fork failed");
            exit(1);
        }
    }

    for (int i = 0; i < CHILD_COUNT; i++) {
        pid_t finished_child = wait(&status);

        if (WIFEXITED(status)) {
            int exitCode = WEXITSTATUS(status);

            time_t now = time(NULL);
            struct tm *localTime = localtime(&now);

            char timeStr[20];
            strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", localTime);

            printf("%d process successfully finished at %s with status code %d.\n",
                   finished_child, timeStr, exitCode);
        }
    }

    return 0;
}