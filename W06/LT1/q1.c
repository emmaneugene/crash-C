/*
   Name : Emmanuel Oh Eu-Gene
   Email: emmanueloh.2019@sis.smu.edu.sg
 */

#include <stdio.h>

int get_quadrant(int x, int y) {
    // Corner case
    if (x == 0 || y == 0) {
        return 0;
    }

    // Split into 4 cases
    if (x > 0) {
        if (y > 0) {
            return 1;
        }
        return 4;
    } else {
        if (y > 0) {
            return 2;
        }
        return 3;
    }
}

int main(void) {
    {
        printf("Test 1\n");
        int result1 = get_quadrant(3, 5);
        printf("Expected:1\n");
        printf("Actual  :%d\n", result1);
        printf("\n");
    }

    {
        printf("Test 2\n");
        int result1 = get_quadrant(-3, 5);
        printf("Expected:2\n");
        printf("Actual  :%d\n", result1);
        printf("\n");
    }

    {
        printf("Test 4\n");
        int result1 = get_quadrant(3, -3);
        printf("Expected:4\n");
        printf("Actual  :%d\n", result1);
        printf("\n");
    }

    {
        printf("Test 5\n");
        int result1 = get_quadrant(0, 0);
        printf("Expected:0\n");
        printf("Actual  :%d\n", result1);
        printf("\n");
    }
}