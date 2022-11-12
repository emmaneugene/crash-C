#include <stdio.h>
#include <stdlib.h>

// Shift each element backwards by 1, n number of times
// Low space complexity, high time complexity

void rotate(int arr[], int n, int shift) {
    // Get absolute value of shift
    shift %= n;
    
    int temp = 0;

    for (int i = 0; i < shift; i++) {
        temp = arr[0];
        for (int j = 1; j < n; j++) {
            arr[j - 1] = arr[j];
        }
        arr[n - 1] = temp;
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