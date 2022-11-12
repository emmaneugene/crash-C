#include <stdio.h>

int binary_search(int count, int arr[], int val) {
    int low = 0;
    int high = count - 1;
    int mid = low + (high - low) / 2;

    while (low <= high) {
        if (val > arr[mid]) {
            low = mid + 1;
        } else if (val < arr[mid]) {
            high = mid - 1;
        } else if (val == arr[mid]) {
            return mid;
        }
        // Find new middle
        mid = low + (high - low) / 2;
    }

    return -1;
}

int main(void) {
    {
        int arr[] = {2, 3, 7, 11, 15, 33, 35, 67, 78, 99};
        int pos = binary_search(sizeof(arr) / sizeof(int), arr, 67);
        printf("Test 1\n");
        printf("Expected:7\n");
        printf("Actual  :%d\n", pos);
        printf("\n");
    }

    {
        int arr[] = {2, 3, 7, 11, 15, 33, 35, 67, 78, 99};
        int pos = binary_search(sizeof(arr) / sizeof(int), arr, 2);
        printf("Test 2\n");
        printf("Expected:0\n");
        printf("Actual  :%d\n", pos);
        printf("\n");
    }

    {
        int arr[] = {2, 3, 7, 11, 15, 33, 35, 67, 78, 99};
        int pos = binary_search(sizeof(arr) / sizeof(int), arr, 68);
        printf("Test 3\n");
        printf("Expected:-1\n");
        printf("Actual  :%d\n", pos);
        printf("\n");
    }
}