#include <stdio.h>

int own_strlen(char* string) {
    int length = 0;
    while (string[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char* string = "Hello, world!";
    int length = own_strlen(string);

    printf("Length of the string: %d\n", length);
    
    return 0;
}