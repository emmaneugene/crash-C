#include <stdio.h>

int partition(int arr[], int lo, int hi);

void quicksort(int arr[], int lo, int hi);

void union_of_2(int arr1Size, int arr1[], int arr2Size, int arr2[], int result[]) {
    // Copy
    int ind = 0;
    for (int i = 0; i < arr1Size; i++) {
        result[ind++] = arr1[i];
    }

    for (int i = 0; i < arr2Size; i++) {
        result[ind++] = arr2[i];
    }

    // Sort
    quicksort(result, 0, ind - 1);
}

void print_array(int size, int result[]) {
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main(void) {
    {
        int arr1[] = {5,3,1};
        int arr2[] = {6,2,4};
        int result[6];
        union_of_2(sizeof(arr1)/sizeof(int), arr1, sizeof(arr2)/sizeof(int), arr2, result);
        printf("Test 1\n");
        printf("Expected:1 2 3 4 5 6\n");
        printf("Actual  :");
        print_array(sizeof(result)/sizeof(int), result);
        printf("\n");
    }

    {
        int arr1[] = {5,3,1,7};
        int arr2[] = {6,2,4};
        int result[7];
        union_of_2(sizeof(arr1)/sizeof(int), arr1, sizeof(arr2)/sizeof(int), arr2, result);
        printf("Test 2\n");
        printf("Expected:1 2 3 4 5 6 7\n");
        printf("Actual  :");
        print_array(sizeof(result)/sizeof(int), result);
        printf("\n");
    }

    {
        int arr1[] = {5,3,1};
        int arr2[] = {6,2,4,8};
        int result[7];
        union_of_2(sizeof(arr1)/sizeof(int), arr1, sizeof(arr2)/sizeof(int), arr2, result);
        printf("Test 3\n");
        printf("Expected:1 2 3 4 5 6 8\n");
        printf("Actual  :");
        print_array(sizeof(result)/sizeof(int), result);
        printf("\n");
    }

    {
        int arr1[] = {1,3,5};
        int arr2[] = {7,9};
        int result[5];
        union_of_2(sizeof(arr1)/sizeof(int), arr1, sizeof(arr2)/sizeof(int), arr2, result);
        printf("Test 4\n");
        printf("Expected:1 3 5 7 9\n");
        printf("Actual  :");
        print_array(sizeof(result)/sizeof(int), result);
        printf("\n");
    }

    {
        int arr1[] = {1,3,5,8};
        int arr2[] = {7,9,9};
        int result[7];
        union_of_2(sizeof(arr1)/sizeof(int), arr1, sizeof(arr2)/sizeof(int), arr2, result);
        printf("Test 5\n");
        printf("Expected:1 3 5 7 8 9 9\n");
        printf("Actual  :");
        print_array(sizeof(result)/sizeof(int), result);
        printf("\n");
    }
}

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
