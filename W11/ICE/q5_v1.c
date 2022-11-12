#include <stdio.h>
#include <stdlib.h>

int min(int n1, int n2) {
    return n1 > n2 ? n2 : n1;
}

int partition(int arr[], int lo, int hi);

void quicksort(int arr[], int lo, int hi);

int intersection_of_2(int arr1Size, int arr1[], int arr2Size, int arr2[], int **result) {
    int tempSize = min(arr1Size, arr2Size);
    *result = malloc(tempSize * sizeof(int));
    int resultSize = 0;

    // Find intersect
    for (int i = 0; i < arr1Size; i++) {
        for (int j = 0; j < arr2Size; j++) {
            if (arr1[i] == arr2[j]) {
                (*result)[resultSize] = arr1[i];
                resultSize++;
                arr2[j] = -1;
                break;
            }
        }
    }
    
    // Sort
    quicksort(*result, 0, resultSize - 1);

    // Reallocate size of *result
    *result = realloc(*result, resultSize * sizeof(int));
    return resultSize;
}

void print_array(int n, int arr[n]) {
    if (n == 0) {
        printf("><\n");
        return;
    }
    printf(">");
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d<\n", arr[n - 1]);
}

int main(void) {
    {
        int arr1[] = {5, 3, 1};
        int arr2[] = {5, 3, 4, 6};
        int *result;
        int n = intersection_of_2(sizeof(arr1) / sizeof(int), arr1, sizeof(arr2) / sizeof(int), arr2, &result);
        printf("Test 1\n");
        printf("Expected:>3 5<\n");
        printf("Actual  :");
        print_array(n, result);
        printf("\n");
        print_array(sizeof(arr2) / sizeof(int), arr2);
    }

    {
        int arr1[] = {5, 3, 1};
        int arr2[] = {4, 6, 9, 10};
        int *result;
        int n = intersection_of_2(sizeof(arr1) / sizeof(int), arr1, sizeof(arr2) / sizeof(int), arr2, &result);
        printf("Test 2\n");
        printf("Expected:><\n");
        printf("Actual  :");
        print_array(n, result);
        printf("\n");
    }

    {
        int arr1[] = {5, 3, 1, 11, 9};
        int arr2[] = {4, 6, 9, 10};
        int *result;
        int n = intersection_of_2(sizeof(arr1) / sizeof(int), arr1, sizeof(arr2) / sizeof(int), arr2, &result);
        printf("Test 3\n");
        printf("Expected:>9<\n");
        printf("Actual  :");
        print_array(n, result);
        printf("\n");
    }

    {
        int arr1[] = {5, 3, 1, 11, 9};
        int arr2[] = {5, 3, 1, 0, 9};
        int *result;
        int n = intersection_of_2(sizeof(arr1) / sizeof(int), arr1, sizeof(arr2) / sizeof(int), arr2, &result);
        printf("Test 4\n");
        printf("Expected:>1 3 5 9<\n");
        printf("Actual  :");
        print_array(n, result);
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