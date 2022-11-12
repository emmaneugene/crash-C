/*
   Name : Emmanuel Oh Eu-Gene
   Email: emmanueloh.2019@sis.smu.edu.sg
 */

#include <stdio.h>
/* 
An exercise in thinking with recursion

what is steal(n)?

worth[n - 1] + steal(n -2) > steal(n-1) ? :

base cases: n = 1 and n = 2
 */

int steal(int worth[], int num) {
    if (num == 1) {
        // Base case 1
        return worth[0];
    } else if (num == 2) {
        // Base case 2
        return worth[1] > worth[0] ? worth[1] : worth[0];
    } else {
        return steal(worth, num - 2) + worth[num - 1] > steal(worth, num - 1) ? steal(worth, num - 2) + worth[num - 1] : steal(worth, num - 1);
    }
}

int main(void) {
    {
        printf("Test 1\n"); 
        printf("Expected:1\n");
        int worth[1] = {1};
        printf("Actual  :%d\n", steal(worth, 1));
        printf("\n");
    }

    {
        printf("Test 2\n");
        printf("Expected:5\n");
        int worth[2] = {1, 5};
        printf("Actual  :%d\n", steal(worth, 2));
        printf("\n");
    }

    {
        printf("Test 3\n");
        printf("Expected:5\n");
        int worth[3] = {1, 5, 3};
        printf("Actual  :%d\n", steal(worth, 3));
        printf("\n");
    }

    {
        printf("Test 4\n");
        printf("Expected:15\n");
        int worth[4] = {1, 5, 3, 10};
        printf("Actual  :%d\n", steal(worth, 4));
        printf("\n");
    }

    {
        printf("Test 5\n");
        printf("Expected:35\n");
        int worth[5] = {1, 5, 3, 10, 30};
        printf("Actual  :%d\n", steal(worth, 5));
        printf("\n");
    }
}