#include <stdio.h>

void longest_common_suffix(char *s1, char *s2, char *s3) {
    // Get to the end of the suffix for both characters
    int s1_count = 0;
    int s2_count = 0;
    while (*(s1 + s1_count) != '\0') {
        s1_count++;
    }
    while (*(s2 + s2_count) != '\0') {
        s2_count++;
    }

    // Working backwards, check if characters are the same
    int s3_count = 0;
    while (s1_count >= 0 && s2_count >= 0 && *(s1 + s1_count) == *(s2 + s2_count)) {
        *(s3 + s3_count++) = *(s1 + s1_count--);
        s2_count--;
    }

    // Reverse string in s3
    char temp;
    for (int i = 0; i < s3_count / 2; i++) {
        temp = s3[i];
        s3[i] = s3[s3_count - 1 - i];
        s3[s3_count - 1 - i] = temp;
    }
}

int main(void) {
    {
        char *s1 = "incident";
        char *s2 = "accident";
        char s3[20];
        longest_common_suffix(s1, s2, s3);
        printf("Test 1\n");
        printf("Expected:cident\n");
        printf("Actual  :%s\n", s3);
        printf("\n");
    }

    {
        char *s1 = "crocodile";
        char *s2 = "horse";
        char s3[20];
        longest_common_suffix(s1, s2, s3);
        printf("Test 2\n");
        printf("Expected:e\n");
        printf("Actual  :%s\n", s3);
        printf("\n");
    }

    {
        char *s1 = "eat";
        char *s2 = "treat";
        char s3[20];
        longest_common_suffix(s1, s2, s3);
        printf("Test 3\n");
        printf("Expected:eat\n");
        printf("Actual  :%s\n", s3);
        printf("\n");
    }

    {
        char *s1 = "discontent";
        char *s2 = "discontinue";
        char s3[20];
        longest_common_suffix(s1, s2, s3);
        printf("Test 4\n");
        printf("Expected:><\n");
        printf("Actual  :>%s<\n", s3);
        printf("\n");
    }
}
