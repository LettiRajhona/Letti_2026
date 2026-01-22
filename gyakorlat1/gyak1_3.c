#include <stdio.h>
#include <string.h>

int main() {
    char word[100];

    printf("Readable word: ");
    scanf("%s", word);

    if (strchr(word, 'e') != NULL) {
        printf("The word contains the letter 'e'.\n");
        printf("First appearance of 'e' at index: %ld\n", strchr(word, 'e') - word);
        printf("Last appearance of 'e' at index: %ld\n", strrchr(word, 'e') - word);
    } else {
        printf("The word does not contain the letter 'e'.\n");
    }

    char* concatenatedWord = strcat(word, "!!!");

    printf("Concatenated word: %s\n", concatenatedWord);

    return 0;
}