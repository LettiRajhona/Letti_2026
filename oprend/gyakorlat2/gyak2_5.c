#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Please add an existing filename as a command line argument.\n");
        return 1;
    }

    const char *filename = argv[1];

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file: file not found");
        return 1;
    }

    int character;
    int line_count = 0;
    int char_count = 0;

    while ((character = fgetc(file)) != EOF) {
        char_count++;
        if (character == '\n') {
            line_count++;
        }
    }

    fclose(file);

    printf("Number of lines: %d\n", line_count);
    printf("Number of characters: %d\n", char_count);

    return 0;
}