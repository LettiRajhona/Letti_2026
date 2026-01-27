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
    int n;

    printf("Add the length of the array: ");
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

    int result = first_greater_than_15(array, n);

    if (result != -1) {
        printf("First number > 15: %d\n", result);
    } else {
        printf("No number greater than 15.\n");
    }

    free(array);
    return 0;
}
