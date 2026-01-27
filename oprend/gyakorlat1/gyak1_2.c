#include <stdio.h>

void reverse_array(int array[], int reversed[], int size) {
    for (int i = 0; i < size; i++) {
        reversed[i] = array[size - 1 - i];
    }
}

int main() {
    int numbers[] = {3, 5, 1, 8, -2, 7};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int reversed[size];
    reverse_array(numbers, reversed, size);

    printf("Reversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", reversed[i]);
    }   

    return 0;
}