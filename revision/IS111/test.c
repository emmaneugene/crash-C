#include <stdio.h>
#include <string.h>

int main(void) {
    char sentence[] = "Hello, world";
    char copy[100];
    strcpy(copy, sentence);
    printf("%s\n", copy);

    int len = strlen(sentence);
    strcpy(copy + len, sentence);
    printf("%s\n", copy);

    strcpy(copy + len, "chicken");
    printf("%s\n", copy);
}