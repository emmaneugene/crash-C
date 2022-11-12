#include <stdio.h>
#include <ctype.h>
#include <string.h>

int total(char *string) {
    int total = 0;
    int value;
    sscanf(string, "%d", &value);
    total += value;
    while (*string != '\0') {
        string++;
        
        if (!isdigit(*string) && *string != '\0') {
            sscanf(string, "%d", &value);
            total += value;
        }
    }    
    return total;
}

int main(void) {
    {
        printf("Test 1\n");
        printf("Expected:6\n");
        int result = total("1 2 3");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        printf("Expected:3\n");
        int result = total("3");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        printf("Expected:1368\n");
        int result = total("11 123 1234");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}