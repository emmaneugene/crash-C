/*
   Name : Emmanuel Oh Eu-Gene
   Email: emmanueloh.2019@sis.smu.edu.sg
 */

#include <stdio.h>
/* 
2 variables, temp and current_greatest
Increment one by one through the array
compare if temp + worth[i] > current_greatest
 */

int max(int n1, int n2) {
    return n1 > n2 ? n1 : n2;
}

int steal(int worth[], int num) {
    // Corner case
    if (num == 1) {
        return worth[0];
    } else if (num == 2) {
        return max(worth[0], worth[1]);
    }

    int previous_greatest = worth[0];
    int current_greatest = max(worth[0], worth[1]);
    int temp;

    for (int i = 2; i < num; i++) {
        // Save the value of current_greatest
        temp = current_greatest;
        // Reassign current_greatest
        current_greatest = max(previous_greatest + worth[i], current_greatest);
        // Reassign previous_greatest
        previous_greatest = temp;
    }

    return current_greatest;
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