#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


bool is_palindrome(char string[]) {
    // Assign a variable constant to string[] to save function calls
    int len = strlen(string);

    // First, clean up the string(this array needs no null character)
    char cleaned_str[len];

    // Index for new string
    int index = 0;

    // Get cleaned_str
    for (int i = 0; i < len; i++) {
        if (isalpha(string[i])) {
            cleaned_str[index] = tolower(string[i]);
            index++;
        }
    }

    // We know that the value of index is the length of the string
    // We can compare indexed characters from front to back. Return false when we find one that's different
    for (int i = 0; i < index / 2; i++) {
        if (cleaned_str[i] != cleaned_str[index - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    {
        printf("Test 1\n");
        char string[] = "madam";
        bool result = is_palindrome(string);
        printf("Expected:True\n");
        printf("Actual  :%s\n", result ? "True" : "False");
        printf("\n");
    }

    {
        printf("Test 2\n");
        char string[] = "No 'x' in Nixon";
        bool result = is_palindrome(string);
        printf("Expected:True\n");
        printf("Actual  :%s\n", result ? "True" : "False");
        printf("\n");
    }

        {
        printf("Test 3\n");
        char string[] = "bad, chocolate dab";
        bool result = is_palindrome(string);
        printf("Expected:False\n");
        printf("Actual  :%s\n", result ? "True" : "False");
        printf("\n");
    }
}


// Sample Run 3:
// Enter the string :
// The string "bad, chocolate dab" is not a palindrome
