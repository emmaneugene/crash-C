#include <stdio.h>
#include <stdbool.h>

bool is_binary_number(int n){
    int next_digit;
    while (n > 0) {
        next_digit = n % 10;
        if (next_digit > 1) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main(void) {
    {
        printf("Test 1\n");
        bool result = is_binary_number(10);
        printf("Expected:Pass\n");
        printf("Actual  :%s\n\n", result ? "Pass" : "Fail");
    }

    {
        printf("Test 2\n");
        bool result = is_binary_number(8);
        printf("Expected:Fail\n");
        printf("Actual  :%s\n\n", result ? "Pass" : "Fail");
    }

    {
        printf("Test 3\n");
        bool result = is_binary_number(10111111);
        printf("Expected:Pass\n");
        printf("Actual  :%s\n\n", result ? "Pass" : "Fail");
    }
}
