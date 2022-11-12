#include <stdio.h>

// Tail recursion

unsigned long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return 1;
    }
}

int main(void) {
    {
        unsigned long result = factorial(5);
        printf("Test 1\n");
        printf("Expected:120\n");
        printf("Actual  :%lu\n", result);
        printf("\n");
    }

    {
        unsigned long result = factorial(15);
        printf("Test 2\n");
        printf("Expected:1307674368000\n");
        printf("Actual  :%lu\n", result);
        printf("\n");
    }

    {
        unsigned long result = factorial(0);
        printf("Test 3\n");
        printf("Expected:1\n");
        printf("Actual  :%lu\n", result);
        printf("\n");
    }

    {
        unsigned long result = factorial(1);
        printf("Test 4\n");
        printf("Expected:1\n");
        printf("Actual  :%lu\n", result);
        printf("\n");
    }
}