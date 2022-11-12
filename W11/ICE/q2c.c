#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
    // the parameter is the "n" - th to generate
    {
        int result = fibonacci(0);
        printf("Test 1\n");
        printf("Expected:0\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        int result = fibonacci(1);
        printf("Test 2\n");
        printf("Expected:1\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        int result = fibonacci(2);
        printf("Test 3\n");
        printf("Expected:1\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
    {
        int result = fibonacci(3);
        printf("Test 4\n");
        printf("Expected:2\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        int result = fibonacci(4);
        printf("Test 5\n");
        printf("Expected:3\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        int result = fibonacci(5);
        printf("Test 6\n");
        printf("Expected:5\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        int result = fibonacci(6);
        printf("Test 7\n");
        printf("Expected:8\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        int result = fibonacci(7);
        printf("Test 8\n");
        printf("Expected:13\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}
