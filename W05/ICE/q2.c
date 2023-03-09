#include <stdio.h>

int max2(int n1, int n2){
    return (n1 > n2) ? n1 : n2;
}

int max3(int n1, int n2, int n3){
    return max2(max2(n1, n2), n3);
}

int main(void) {
    {
        printf("Test 1\n");
        int result = max2(3, 2);
        printf("Expected:3\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 2\n");
        int result = max2(2, 4);
        printf("Expected:4\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 3\n");
        int result = max2(3, 3);
        printf("Expected:3\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 4\n");
        int result = max2(-3, 3);
        printf("Expected:3\n");
        printf("Actual  :%d\n\n", result);
    }

    // uncomment to test max3
    {
        printf("Test 5\n");
        int result = max3(1, 2, 3);
        printf("Expected:3\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 6\n");
        int result = max3(5, 11, 3);
        printf("Expected:11\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 7\n");
        int result = max3(30, 1, 3);
        printf("Expected:30\n");
        printf("Actual  :%d\n\n", result);
    }
}
