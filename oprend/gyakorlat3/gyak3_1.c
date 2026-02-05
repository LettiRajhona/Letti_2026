#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int parent = 0, child = 0;

    printf("Enter the number of parents: ");
    scanf("%d", &parent);

    printf("Enter the number of children: ");
    scanf("%d", &child);

    pid_t pid = fork();

    if (pid > 0) {
        for (int i = 0; i < parent; i++) {
            printf("I am the parent! Process ID: %d\n", getpid());
            sleep(1);
        }
    } else if (pid == 0) {
        for (int i = 0; i < child; i++) {
            printf("And? Process ID: %d\n", getpid());
            sleep(1);
        }
    } else {
        perror("Fork failed");
        exit(1);
    }


    return 0;
}