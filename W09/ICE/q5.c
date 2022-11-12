#include <stdio.h>

void my_strcat(char* dest, char* src) {
    // Find out where we start from
    while (*dest != '\0') {
        dest++;
    }

    // Copy over source
    while (*src != '\0') {
        *dest++ = *src++;
    }

    // Finish string
    *dest = '\0';
}

int main(void) {
    {
        char dest[10] = "pear";
        char src[5] = "kiwi";
        my_strcat(dest, src);
        printf("Test 1\n");
        printf("Expected:pearkiwi\n");
        printf("Actual  :%s\n", dest);
        printf("\n");
    }

    {
        char dest[10] = "";
        char src[5] = "kiwi";
        my_strcat(dest, src);
        printf("Test 2\n");
        printf("Expected:kiwi\n");
        printf("Actual  :%s\n", dest);
        printf("\n");
    }

    {
        char dest[10] = "kiwi";
        char src[5] = "";
        my_strcat(dest, src);
        printf("Test 3\n");
        printf("Expected:kiwi\n");
        printf("Actual  :%s\n", dest);
        printf("\n");
    }

    {
        char dest[10] = "";
        char src[5] = "";
        my_strcat(dest, src);
        printf("Test 4\n");
        printf("Expected:><\n");
        printf("Actual  :>%s<\n", dest);
        printf("\n");
    }
}