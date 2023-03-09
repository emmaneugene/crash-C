#include <stdio.h>

void longest_common_prefix(char *s1, char *s2, char *s3) {
    // Compare and copy
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        *s3++ = *s1++;
        s2++;
    }

    // Finish string
    *s3 = '\0';
}

int main(void) {
    {
        char *s1 = "happy";
        char *s2 = "happen";
        char s3[10];
        longest_common_prefix(s1, s2, s3);
        printf("Test 1\n");
        printf("Expected:happ\n");
        printf("Actual  :%s\n", s3);
        printf("\n");
    }

    {
        char *s1 = "manual";
        char *s2 = "man";
        char s3[10];
        longest_common_prefix(s1, s2, s3);
        printf("Test 2\n");
        printf("Expected:man\n");
        printf("Actual  :%s\n", s3);
        printf("\n");
    }

    {
        char *s1 = "good";
        char *s2 = "food";
        char s3[10];
        longest_common_prefix(s1, s2, s3);
        printf("Test 3\n");
        printf("Expected:><\n");
        printf("Actual  :>%s<\n", s3);
        printf("\n");
    }

    {
        char *s1 = "good";
        char *s2 = "goodie";
        char s3[10];
        longest_common_prefix(s1, s2, s3);
        printf("Test 4\n");
        printf("Expected:good\n");
        printf("Actual  :%s\n", s3);
        printf("\n");
    }
}
