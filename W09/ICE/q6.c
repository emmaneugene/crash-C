#include <stdio.h>

void my_strcpy(char* dest, char* src) {
    while (*src != '\0') {
        *dest++ = *src++;
    }
    
    // Indicate end of string
    *dest = '\0';
}

int main(void) {
    {
        char dest[10];
        char src[5] = "kiwi";
        my_strcpy(dest, src);
        printf("Test 1\n");
        printf("Expected:kiwi\n");
        printf("Actual  :%s\n", dest);
        printf("\n");
    }

    {
        char dest[10];
        char src[5] = "";
        my_strcpy(dest, src);
        printf("Test 2\n");
        printf("Expected:><\n");
        printf("Actual  :>%s<\n", dest);
        printf("\n");
    }

    {
        char dest[10];
        char src[2] = "a";
        my_strcpy(dest, src);
        printf("Test 3\n");
        printf("Expected:a\n");
        printf("Actual  :%s\n", dest);
        printf("\n");
    }
}