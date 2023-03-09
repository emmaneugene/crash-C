/*
   Name : Emmanuel Oh Eu-Gene
   Email: emmanueloh.2019@sis.smu.edu.sg
 */

#include <stdbool.h>
#include <stdio.h>

int num_half_it(int n1, int n2) {
    // Corner case
    if (n1 <= 0 || n2 <= 0) {
        return -1;
    }

    // Get larger number and smaller number, both as double
    // Assume n2 is larger then n1 first
    double max = (double)n2;
    double min = (double)n1;
    if (n1 > n2) {
        max = (double)n1;
        min = (double)n2;
    }

    int count = 0;

    while (max / 2 > min) {
        count++;
        max /= 2;
    }
    return count;
}

int main(void) {

    {
        printf("Test 1\n");
        int result = num_half_it(100, 4);
        printf("Expected:4\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        int result = num_half_it(24, 7);
        printf("Expected:1\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        int result = num_half_it(135, 5);
        printf("Expected:4\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 4\n");
        int result = num_half_it(5, 135);
        printf("Expected:4\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 5\n");
        int result = num_half_it(132, 1);
        printf("Expected:7\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 6\n");
        int result = num_half_it(-1, 1);
        printf("Expected:-1\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 7\n");
        int result = num_half_it(1, 1);
        printf("Expected:0\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}
