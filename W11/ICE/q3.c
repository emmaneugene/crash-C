#include <stdio.h>

int partition(int arr[], int lo, int hi) {
    // Set pivot as last element
    int pivot = arr[hi];
    int i = lo;
    int temp;

    for (int j = i; j < hi; j++) {
        if (arr[j] < pivot) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    temp = arr[i];
    arr[i] = arr[hi];
    arr[hi] = temp;
    return i;
}

void quicksort(int arr[], int lo, int hi) {
    if (lo < hi) {
        int mid = partition (arr, lo, hi);
        quicksort(arr, lo, mid - 1);
        quicksort(arr, mid + 1, hi);
    }
}

void print_array(int size, int result[]) {
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main(void) {
    {
        int arr[] = {3, 7, 8, 5, 2, 1, 9, 5, 4};
        printf("Test 1\n");
        printf("Before:");
        print_array(sizeof(arr) / sizeof(int), arr);
        quicksort(arr, 0, sizeof(arr) / sizeof(int) - 1);
        printf("After :");
        print_array(sizeof(arr) / sizeof(int), arr);
        printf("\n");
    }

    {
        int arr[] = {1, 2, 4};
        printf("Test 2\n");
        printf("Before:");
        print_array(sizeof(arr) / sizeof(int), arr);
        quicksort(arr, 0, sizeof(arr) / sizeof(int) - 1);
        printf("After :");
        print_array(sizeof(arr) / sizeof(int), arr);
        printf("\n");
    }

    {
        int arr[] = {5, 3, 1};
        printf("Test 3\n");
        printf("Before:");
        print_array(sizeof(arr) / sizeof(int), arr);
        quicksort(arr, 0, sizeof(arr) / sizeof(int) - 1);
        printf("After :");
        print_array(sizeof(arr) / sizeof(int), arr);
        printf("\n");
    }

    {
        int arr[] = {5};
        printf("Test 4\n");
        printf("Before:");
        print_array(sizeof(arr) / sizeof(int), arr);
        quicksort(arr, 0, sizeof(arr) / sizeof(int) - 1);
        printf("After :");
        print_array(sizeof(arr) / sizeof(int), arr);
        printf("\n");
    }
}
