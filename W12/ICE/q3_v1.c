#include <stdio.h>
#include <stdlib.h>

// High space complexity, low time complexity

void rotate(int arr[], int n, int shift) {
    // Get absolute value of shift
    shift %= n;
    // Change to forward shift
    shift = n - shift;

    // Make copy
    int arr_copy[n];
    for (int i = 0; i < n; i++) {
        arr_copy[i] = arr[i];
    }
    // Shift
    for (int i = 0; i < n; i++) {
        arr[(i + shift) % n] = arr_copy[i];
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
