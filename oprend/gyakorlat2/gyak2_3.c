#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t time_start = time(NULL);

    int* array = (int*)malloc(10 * sizeof(int));
    printf("Dinamically allocated array of numbers:\n");
    
    srand(time_start);
    for (int i = 0; i < 10; i++) {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }

    free(array);

    time_t time_end = time(NULL);
    double elapsed = difftime(time_end, time_start);

    printf("\nElapsed time between starting and ending the program: %.5f seconds\n", elapsed);

    return 0;
}