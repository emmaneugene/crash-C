#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// functions to create a string in heap memory, and resize it to be larger should more characters be added

char *new_string(int len) {
    return calloc((len + 1), sizeof(char));
}

void append(char *src, char *dest) {
    int len = strlen(src) + strlen(dest);

    dest = realloc(dest, (len + 1) * sizeof(char));

    while (*dest) {
        dest++;
    }

    while (*src) {
        *dest++ = *src++;
    }
    *dest = *src;
}

int main(void) {
    char* string = new_string(10);

    printf("%s\n", string);

    append("hello", string);
    printf("%s\n", string);

    append("world", string);
    printf("%s\n", string);
}
