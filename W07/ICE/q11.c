#include <stdio.h>

int my_strcmp(char word1[], char word2[]) {
    int index = 0;
    while (word1[index] == word2[index] && word1[index] != 0 && word2[index] != 0) {
        index++;
    }
    return word1[index] - word2[index];
}

int main(void) {
    {
        printf("Test 1\n");
        int result = my_strcmp("abc", "abb");
        printf("Expected:1\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        int result = my_strcmp("ab", "abcdef");
        printf("Expected:-99\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }


    {
        printf("Test 3\n");
        int result = my_strcmp("abcdef", "ab");
        printf("Expected:99\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        int result = my_strcmp("AB", "Ab");
        printf("Expected:-32\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 4\n");
        int result = my_strcmp("", "Ab");
        printf("Expected:-65\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}
