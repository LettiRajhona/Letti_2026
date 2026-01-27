#include <stdio.h>
#include <stdlib.h>

int first_greater_than_15(int *array, int length) {
    for (int i = 0; i < length; i++) {
        if (array[i] > 15) {
            return array[i];
        }
    }
    return -1;
}

int main() {
    int n, m;

    printf("Add the original length of the array: ");
    scanf("%d", &n);

    int *array = malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int value;
        do {
            printf("Add the %d. element (1-20): ", i + 1);
            scanf("%d", &value);
        } while (value < 1 || value > 20);

        array[i] = value;
    }

    printf("Add the new size of the array (m): ");
    scanf("%d", &m);

    int *temp = realloc(array, m * sizeof(int));
    if (temp == NULL) {
        printf("Memory reallocation error!\n");
        free(array);
        return 1;
    }
    array = temp;

    if (m > n) {
        for (int i = n; i < m; i++) {
            array[i] = -1;
        }
    }

    int result = first_greater_than_15(array, m);

    if (result != -1) {
        printf("First number > 15: %d\n", result);
    } else {
        printf("No number greater than 15.\n");
    }

    printf("Array elements:\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}
