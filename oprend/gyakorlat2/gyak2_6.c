#include <stdio.h>

int main() {
    FILE* file = fopen("structured_data.txt", "r");
    if (file == NULL) {
        printf("Error opening file: file not found.\n");
        return 1;
    }

    char name[50], city[50];
    int age;

    fscanf(file, "%*s %*s %*s"); // skip header line

    while (fscanf(file, "%49s %d %49s", name, &age, city) == 3) {
        if (age >= 20 && age <= 30) {
            printf("Name: %s, city: %s\n", name, city);
        }
    }

    fclose(file);

    return 0;
}