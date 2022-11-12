#include <stdio.h>

int my_strlen(char string[]) {
    int count = 0;
    while (string[count] != 0) {
        count++;
    }
    return count;
}


int main(void) {
    {
        printf("Test 1\n");
        char input[] = "apple";
        int result = my_strlen(input);
        printf("Expected:5\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        char input[] = "apple is red";
        int result = my_strlen(input);
        printf("Expected:12\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        char input[] = "a";
        int result = my_strlen(input);
        printf("Expected:1\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 4\n");
        char input[] = "";
        int result = my_strlen(input);
        printf("Expected:0\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}
