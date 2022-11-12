#include <stdio.h>

// Array version

void compare_values(int *max1, int *max2, int next) {
    if (next > *max1) {
        *max2 = *max1;
        *max1 = next;
    } else if (next > *max2) {
        *max2 = next;
    }
}

void print_largest_two(int values[], int n) {
    // Corner case
    if (n == 0) {
        printf("No values");
        return;
    } else if (n == 1) {
        printf("#1 = %d", values[0]);
        return;
    }

    // Get max1 and max2 in order
    int max1 = values[0];
    int max2 = values[1];
    if (max2 > max1) {
        max1 = values[1];
        max2 = values[0];
    }

    // Iterate over the rest of the array and compare the elements
    for (int i = 2; i < n; i++) {
        compare_values(&max1, &max2, values[i]);
    }
    
    // Print our maximum 2 values in order
    printf("#1 = %d, #2 = %d", max1, max2);
}

int main(void) {
    {
        int numbers[] = {13, 5, 6, 11};
        printf("Test 1\n");
        printf("Expected:#1 = 13, #2 = 11\n");
        printf("Actual  :");
        print_largest_two(numbers, sizeof(numbers) / sizeof(int));
        printf("\n");
    }

    {
        int numbers[] = {13, 13, 6, 11};
        printf("Test 2\n");
        printf("Expected:#1 = 13, #2 = 13\n");
        printf("Actual  :");
        print_largest_two(numbers, sizeof(numbers) / sizeof(int));
        printf("\n");
    }

    {
        int numbers[] = {13, 11, 1, 8, 2, 3, 5, 6, 6, 13};
        printf("Test 3\n");
        printf("Expected:#1 = 13, #2 = 13\n");
        printf("Actual  :");
        print_largest_two(numbers, sizeof(numbers) / sizeof(int));
        printf("\n");
    }

    {
        int numbers[] = {13, 11, 1, 8, 2, 3, 5, 6, 6, 17};
        printf("Test 4\n");
        printf("Expected:#1 = 17, #2 = 13\n");
        printf("Actual  :");
        print_largest_two(numbers, sizeof(numbers) / sizeof(int));
        printf("\n");
    }

    {
        int numbers[] = {21, 11, 1, 8, 2, 3, 5, 6, 6, 17};
        printf("Test 5\n");
        printf("Expected:#1 = 21, #2 = 17\n");
        printf("Actual  :");
        print_largest_two(numbers, sizeof(numbers) / sizeof(int));
        printf("\n");
    }

    {
        int numbers[] = {1, 2};
        printf("Test 6\n");
        printf("Expected:#1 = 2, #2 = 1\n");
        printf("Actual  :");
        print_largest_two(numbers, sizeof(numbers) / sizeof(int));
        printf("\n");
    }

    {
        int numbers[] = {1};
        printf("Test 7\n");
        printf("Expected:#1 = 1\n");
        printf("Actual  :");
        print_largest_two(numbers, sizeof(numbers) / sizeof(int));
        printf("\n");
    }

    {
        int numbers[] = {};
        printf("Test 8\n");
        printf("Expected:No values\n");
        printf("Actual  :");
        print_largest_two(numbers, sizeof(numbers) / sizeof(int));
        printf("\n");
    }
}