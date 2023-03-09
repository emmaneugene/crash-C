#include <stdio.h>
#include <stdbool.h>

bool is_even(int n){
    return (n % 2 == 0);
}

int main(void) {
    {
        printf("Test 1\n");
        bool result = is_even(7102);
        printf("Expected:Pass\n");
        printf("Actual  :%s\n\n", result ? "Pass" : "Fail");
    }

    {
        printf("Test 2\n");
        bool result = is_even(-2);
        printf("Expected:Pass\n");
        printf("Actual  :%s\n\n", result ? "Pass" : "Fail");
    }

    {
        printf("Test 3\n");
        bool result = is_even(0);
        printf("Expected:Pass\n");
        printf("Actual  :%s\n\n", result ? "Pass" : "Fail");
    }

    {
        printf("Test 4\n");
        bool result = is_even(0);
        printf("Expected:Pass\n");
        printf("Actual  :%s\n\n", result ? "Pass" : "Fail");
    }

    {
        printf("Test 5\n");
        bool result = is_even(-13);
        printf("Expected:Fail\n");
        printf("Actual  :%s\n\n", result ? "Pass" : "Fail");
    }
}
