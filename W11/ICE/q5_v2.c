#include <stdio.h>
#include <stdlib.h>

int min(int n1, int n2) {
    return n1 > n2 ? n2 : n1;
}

int partition(int arr[], int lo, int hi);

void quicksort(int arr[], int lo, int hi);

int intersection_of_2(int arr1Size, int arr1[], int arr2Size, int arr2[], int **result) {
    quicksort(arr1, 0, arr1Size - 1);
    quicksort(arr2, 0, arr2Size - 1);

    *result = malloc(min(arr1Size, arr2Size) * sizeof(int));

    int ind1 = 0;
    int ind2 = 0;
    int resultSize = 0;

    while (ind1 != arr1Size && ind2 != arr2Size) {
        if (arr1[ind1] < arr2[ind2]) {
            ind1++;
        } else if (arr1[ind1] > arr2[ind2]) {
            ind2++;
        } else if (arr1[ind1] == arr2[ind2]) {
            (*result)[resultSize++] = arr1[ind1++];
            ind2++;
        }
    }

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
