#include <stdio.h>
#include <stdlib.h>

// Make a sub-array, shift elements by n, copy over sub-array to the end
// Variable space complexity, low time complexity

void rotate(int arr[], int n, int shift) {
    // Get absolute value of shift
    shift %= n;
    
    int sub_arr[shift];
    for (int i = 0; i < shift; i++) {
        sub_arr[i] = arr[i];
    }

    for (int i = 0; i < n - shift; i++) {
        arr[i] = arr[i + shift];
    }

    for (int i = 0; i < shift; i++) {
        arr[n - shift + i] = sub_arr[i];
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    {
        int arr[] = {1, 2, 3, 4, 5};
        rotate(arr, sizeof(arr) / sizeof(int), 2);
        printf("Expected:3 4 5 1 2\n");
        printf("Actual  :");
        print_array(arr, sizeof(arr) / sizeof(int));
        printf("\n");
    }

    {
        int arr[] = {1, 2, 3, 4, 5, 7, 8, 9};
        rotate(arr, sizeof(arr) / sizeof(int), 5);
        printf("Expected:7 8 9 1 2 3 4 5\n");
        printf("Actual  :");
        print_array(arr, sizeof(arr) / sizeof(int));
        printf("\n");
    }

    {
        int arr[] = {1, 2, 3, 4, 5, 7, 8, 9};
        rotate(arr, sizeof(arr) / sizeof(int), 10);
        printf("Expected:3 4 5 7 8 9 1 2\n");
        printf("Actual  :");
        print_array(arr, sizeof(arr) / sizeof(int));
        printf("\n");
    }
}