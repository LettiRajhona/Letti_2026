#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Copy program. Needs a source and a destination file name as arguments.\n");
        return 1;
    }

    FILE *sourceFile = fopen(argv[1], "r");
    FILE *destinationFile = fopen(argv[2], "w");

    if (sourceFile == NULL) {
        perror("Error opening file: file not found");
        return 1;
    }

    int character;
    int lineNumber = 1; // index of current line

    while ((character = fgetc(sourceFile)) != EOF) {
        if (lineNumber % 2 == 0) { // if current line is even
            fputc(character, destinationFile);
        }

        if (character == '\n') {
            lineNumber++;
        }
    }

    fclose(sourceFile);
    fclose(destinationFile);

    printf("Copying completed successfully.\n");

    return 0;
}