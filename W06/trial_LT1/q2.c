/**
 * 
 * Name: Emmanuel Oh Eu-Gene
 * Email: emmanueloh.2019@sis.smu.edu.sg
 * 
*/

#include <stdio.h>
#include <stdlib.h>

int gcd(int num1, int num2) {
    // Corner cases
    if (num1 == 0) {
        return num2;
    }

    if (num2 == 0) {
        return num1;
    }

    // Then, make sure num1 and num2 are positive
    num1 = num1 > 0 ? num1 : -num1;
    num2 = num2 > 0 ? num2 : -num2;

    // Then, start from the smaller number
    int start = num1 < num2 ? num1 : num2;

    for (int i = start; i > 0; i--) {
        if (num1 % i == 0 && num2 % i == 0) {
            return i;
        }
    }
}

int main(void) {
    {
        printf("Test 1\n");
        printf("Expected:3\n");
        int result = gcd(9, 12);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        printf("Expected:1\n");
        int result = gcd(1, 0);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        printf("Expected:1\n");
        int result = gcd(3, 5);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 4\n");
        printf("Expected:3\n");
        int result = gcd(-3, -6);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 5\n");
        printf("Expected:3\n");
        int result = gcd(-3, -6);
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}
