#include <stdio.h>
#include <stdbool.h>

int my_strspn(char str1[], char str2[]) {
    int count = 0;
    bool char_exists;

    // Iterate over each element in str1[]
    for (int i = 0; str1[i] != '\0'; i++) {
        // If str1[i] exists in str2[], continue with the loop. Otherwise, exit
        char_exists = false;

        for (int j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j]) {
                char_exists = true;
                count++;
            }
        }

        if (!char_exists) {
            return count;
        }
        
    }
    return count;
}


int main(void) {
    {
        char str1[] = "apple123";
        char str2[] = "1234567890";
        printf("Test 1\n");
        printf("Expected:0\n");
        printf("Actual  :%d\n", my_strspn(str1, str2));
        printf("\n");
    }

    {
        char str1[] = "apple123";
        char str2[] = "abc";
        printf("Test 2\n");
        printf("Expected:1\n");
        printf("Actual  :%d\n", my_strspn(str1, str2));
        printf("\n");
    }

    {
        char str1[] = "apple123";
        char str2[] = "lap";
        printf("Test 3\n");
        printf("Expected:4\n");
        printf("Actual  :%d\n", my_strspn(str1, str2));
        printf("\n");
    }

    {
        char str1[] = "";
        char str2[] = "lap";
        printf("Test 4\n");
        printf("Expected:0\n");
        printf("Actual  :%d\n", my_strspn(str1, str2));
        printf("\n");
    }
}