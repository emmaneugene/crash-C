#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool find_and_replace_char(char search, char *str2_copy, int len) {
    for (int i = 0; i < len; i++) {
        if (str2_copy[i] == search) {
            str2_copy[i] = '\0';
            return true;
        }
    }
    return false;
}

// We are dealing with string literals, so their values are immutable here
bool is_anagram(char *str1, char *str2) {
    int len = strlen(str1);
    // Copy over str2 to str2_copy
    char str2_copy[len];
    for (int i = 0; str2[i] != '\0'; i++) {
        str2_copy[i] = str2[i];
    }

    // Iterate over str1
    for (int i = 0; i < len; i++) {
        // Look for next char in str2_copy
        if (!find_and_replace_char(str1[i], str2_copy, len)) {
            return false;
        }
    }

    return true;
}

int main(void) {
    {
        printf("Test 1:%s\n", is_anagram("listen","silent") ? "Pass" : "Fail");
        printf("\n");
    }

    {
        printf("Test 2:%s\n", is_anagram("rail safety", "fairy tales") ? "Pass" : "Fail");
        printf("\n");
    }

    {
        printf("Test 3:%s\n", is_anagram("restful", "fluster") ? "Pass" : "Fail");
        printf("\n");
    }

    {
        printf("Test 4:%s\n", is_anagram("restfully", "fluttering") ? "Fail" : "Pass");
        printf("\n");
    }

    {
        printf("Test 5:%s\n", is_anagram("", "") ? "Pass" : "Fail");
        printf("\n");
    }
}
