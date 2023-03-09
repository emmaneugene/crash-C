/**
 *
 * Name: Emmanuel Oh Eu-Gene
 * Email: emmanueloh.2019@sis.smu.edu.sg
 *
 */

#include <stdio.h>

int get_smallest_pair(num) {
    if (num < 10) {
        return -1;
    }
    // Get the very first pair
    int smallest_pair = num % 100;
    // Declare variable for next pair
    int next_pair;
    // Remove the trailing digit before we enter the loop

    while (num >= 10) {
        next_pair = num % 100;
        if (next_pair < smallest_pair) {
            smallest_pair = next_pair;
        }
        num /= 10;
    }
    return smallest_pair;
}

int main(void) {
    {
        printf("Test 1\n");
        printf("Expected:23\n");
        int result = get_smallest_pair(2345);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        printf("Expected:2\n");
        int result = get_smallest_pair(10245);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        printf("Expected:-1\n");
        int result = get_smallest_pair(1);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 4\n");
        printf("Expected:10\n");
        int result = get_smallest_pair(10);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 5\n");
        printf("Expected:-1\n");
        int result = get_smallest_pair(1);
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}
