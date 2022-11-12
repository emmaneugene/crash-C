#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// We are dealing with string literals, so their values are immutable here
bool is_anagram(char *str1, char *str2) {
    int len = strlen(str1);
    // Copy over str2 to str2_copy
    char str2_copy[len];
    for (int i = 0; *(str2 + i) != '\0'; i++) {
        str2_copy[i] = *(str2 + i);
    }

    bool next_char_found;

    // Iterate over str1
    for (int i = 0; i < len; i++) {
        next_char_found = false;

        // Look for next char in str2_copy
        for (int j = 0; j < len; j++) {
            // If found, replace that character in str2_copy with a null character
            if (*(str1 + i) == str2_copy[j]) {
                next_char_found = true;
                str2_copy[j] = '\0';
                break;
            }
        }

        if (!next_char_found) {
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

