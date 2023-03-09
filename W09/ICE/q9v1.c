#include <stdio.h>
#include <stdbool.h>

char* my_strstr(char *haystack, char *needle) {
    // Corner case
    if (*needle == '\0') {
        return haystack;
    }

    bool is_found = false;

    // Iterate over haystack
    for (; *haystack != '\0'; haystack++) {
        if (*haystack == *needle) {
            is_found = true;

            // Check that the rest of the string matches. Otherwise, revert bool to false
            for (int i = 1; *(needle + i) != '\0'; i++) {
                // Don't index past haystack
                if (*(haystack + i) == '\0') {
                    return NULL;
                }

                if (*(haystack + i) != *(needle + i)) {
                    is_found = false;
                }
            }

            if (is_found) {
                return haystack;
            }
        }
    }

    return NULL;
}

int main(void) {
    {
        char *haystack = "this is a simple string";
        char *needle = "simple";
        printf("Test 1\n");
        printf("Expected:simple string\n");
        printf("Actual  :%s\n", my_strstr(haystack, needle));
        printf("\n");
    }

    {
        char *haystack = "this is a simple string";
        char *needle = "";
        printf("Test 2\n");
        printf("Expected:this is a simple string\n");
        printf("Actual  :%s\n", my_strstr(haystack, needle));
        printf("\n");
    }

    {
        char *haystack = "C is a wonderful language";
        char *needle = "Python";
        printf("Test 3\n");
        printf("Expected:(null)\n");
        printf("Actual  :%s\n", my_strstr(haystack, needle));
        printf("\n");
    }

    {
        char *haystack = "apples and oranges";
        char *needle = "apple";
        printf("Test 4\n");
        printf("Expected:apples and oranges\n");
        printf("Actual  :%s\n", my_strstr(haystack, needle));
        printf("\n");
    }

    {
        char *haystack = "apples and oranges";
        char *needle = "orange";
        printf("Test 5\n");
        printf("Expected:oranges\n");
        printf("Actual  :%s\n", my_strstr(haystack, needle));
        printf("\n");
    }

    {
        char *haystack = "apples and orange";
        char *needle = "orangest";
        printf("Test 6\n");
        printf("Expected:(null)\n");
        printf("Actual  :%s\n", my_strstr(haystack, needle));
        printf("\n");
    }

}
