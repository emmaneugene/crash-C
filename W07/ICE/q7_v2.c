#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


bool is_palindrome(char string[]) {
    // Assign a variable constant to string[] to save function calls
    int len = strlen(string);

    int index_1 = 0;
    int index_2 = 0;
    // 'Clean' the string
    for (; index_1 < len; index_1++) {
        if (isalpha(string[index_1])) {
            string[index_2] = tolower(string[index_1]);
            index_2++;
        }
    }

    // We know that the value of index_2 is the length of the cleaned string
    // We can compare indexed characters from front to back. Return false when we find one that's different
    for (int i = 0; i < index_2 / 2; i++) {
        if (string[i] != string[index_2 - 1 - i]) {
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
