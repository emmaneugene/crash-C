#include <stdbool.h>
#include <stdio.h>

bool is_sorted(int numbers[], int count) {
    // Corner case: less than 2 items in array
    if (count < 2) {
        return true;
    }

    // Find out whether the array is increasing or decreasing, based on first 2 differing values
    int index = 0;
    while (numbers[index] == numbers[index + 1]) {
        index++;
    }

    // Corner case: all numbers in array are the same
    if (index == count - 1) {
        return true;
    }

    if (numbers[index] < numbers[index + 1]) {
        // Ascending order
        for (int i = index; i < count - 1; i++) {
            if (numbers[i] > numbers[i + 1]) {
                return false;
            }
        }
    } else {
        // Descending order
        for (int i = index; i < count - 1; i++) {
            if (numbers[i] < numbers[i + 1]) {
                return false;
            }
        }
    }
    
    return true;
}

int main(void) {
    {

        int numbers[] = {2, 3, 4, 5};
        printf("Test 1\n");
        printf("Expected:Pass\n");
        printf("Actual  :%s\n", is_sorted(numbers, sizeof(numbers) / sizeof(int)) ? "Pass" : "Fail");
        printf("\n");
    }

    {

        int numbers[] = {5, 9, 11, 15, 35};
        printf("Test 2\n");
        printf("Expected:Pass\n");
        printf("Actual  :%s\n", is_sorted(numbers, sizeof(numbers) / sizeof(int)) ? "Pass" : "Fail");
        printf("\n");
    }

    {

        int numbers[] = {5, 9, 11, 15, 2};
        printf("Test 3\n");
        printf("Expected:Fail\n");
        printf("Actual  :%s\n", is_sorted(numbers, sizeof(numbers) / sizeof(int)) ? "Pass" : "Fail");
        printf("\n");
    }

    {

        int numbers[] = {15, 11, 3, 2, -1, 0};
        printf("Test 4\n");
        printf("Expected:Fail\n");
        printf("Actual  :%s\n", is_sorted(numbers, sizeof(numbers) / sizeof(int)) ? "Pass" : "Fail");
        printf("\n");
    }

    {

        int numbers[] = {15, 11};
        printf("Test 5\n");
        printf("Expected:Pass\n");
        printf("Actual  :%s\n", is_sorted(numbers, sizeof(numbers) / sizeof(int)) ? "Pass" : "Fail");
        printf("\n");
    }

    {

        int numbers[] = {11};
        printf("Test 6\n");
        printf("Expected:Pass\n");
        printf("Actual  :%s\n", is_sorted(numbers, sizeof(numbers) / sizeof(int)) ? "Pass" : "Fail");
        printf("\n");
    }

    {

        int numbers[] = {};
        printf("Test 7\n");
        printf("Expected:Pass\n");
        printf("Actual  :%s\n", is_sorted(numbers, sizeof(numbers) / sizeof(int)) ? "Pass" : "Fail");
        printf("\n");
    }
}