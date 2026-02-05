#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        wait(NULL);
        printf("The children process program has finished.\n");
    } else if (pid == 0) {
        execlp("ps", "ps", NULL);

        perror("execlp failed");
        exit(1);
    } else {
        perror("Fork failed");
        exit(1);
    }

    return 0;
}