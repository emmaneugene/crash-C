/*
   Name : Emmanuel Oh Eu-Gene
   Email: emmanueloh.2019@sis.smu.edu.sg
 */

#include <stdio.h>
/*
2 pointers iterating through the array

ptr_1: [0], [2], [4], ...
ptr_2: [1], [3], [5], ...

2 sums, max_ptr_1 and max_ptr_2
each time a pointer increments, we will reassign its max_ptr by comparison
 */

int steal(int worth[], int num) {
    // Corner case
    if (num == 1) {
        return worth[0];
    }
    int ptr_1 = 0;
    int ptr_2 = 1;
    int max_ptr_1 = worth[ptr_1];
    int max_ptr_2 = worth[ptr_2];

    while (ptr_2 + 2 < num) {
        ptr_1 += 2;
        // Reassign max_ptr_1
        max_ptr_1 = max_ptr_1 + worth[ptr_1] > max_ptr_2 ? max_ptr_1 + worth[ptr_1] : max_ptr_2;
        ptr_2 += 2;
        // Reassign max_ptr_2
        max_ptr_2 = max_ptr_2 + worth[ptr_2] > max_ptr_1 ? max_ptr_2 + worth[ptr_2] : max_ptr_1;
    }

    // Fencepost for ptr_1, in case we missed out an extra digit
    if (ptr_1 + 2 < num) {
        ptr_1 += 2;
        max_ptr_1 = max_ptr_1 + worth[ptr_1] > max_ptr_2 ? max_ptr_1 + worth[ptr_1] : max_ptr_2;
    }

    return max_ptr_1 > max_ptr_2 ? max_ptr_1 : max_ptr_2;
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
