#include <stdio.h>

typedef struct {
    int min;
    int max;
} MinMax;

MinMax min_max(int numbers[], int size) {
    MinMax values;

    values.min = numbers[0];
    values.max = numbers[0];

    for (int i = 1; i < size; i++) {
        if (numbers[i] < values.min) {
            values.min = numbers[i];
        }
        if (numbers[i] > values.max) {
            values.max = numbers[i];
        }
    }

    return values;
}

int main() {
    int numbers[] = {3, 5, 1, 8, -2, 7};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    MinMax result = min_max(numbers, size);

    printf("Minimum value: %d\n", result.min);
    printf("Maximum value: %d\n", result.max);

    return 0;
}