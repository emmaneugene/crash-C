#include <stdio.h>

// Array version

void my_strupr(char string[]) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] += 'A' - 'a';
        }
    }
}

int main(void) {
    {
        char string[] = "APPLE";
        my_strupr(string);
        printf("Test 1\n");
        printf("Expected:APPLE\n");
        printf("Actual  :%s\n", string);
        printf("\n");
    }

    {
        char string[] = "";
        my_strupr(string);
        printf("Test 2\n");
        printf("Expected:><\n");
        printf("Actual  :>%s<\n", string);
        printf("\n");
    }

    {
        char string[] = "There is 1 APPLE.";
        my_strupr(string);
        printf("Test 3\n");
        printf("Expected:THERE IS 1 APPLE.\n");
        printf("Actual  :%s\n", string);
        printf("\n");
    }

    {
        char string[] = "happy";
        my_strupr(string);
        printf("Test 4\n");
        printf("Expected:HAPPY\n");
        printf("Actual  :%s\n", string);
        printf("\n");
    }
}