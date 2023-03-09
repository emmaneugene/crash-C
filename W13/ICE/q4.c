#include <stdio.h>
#include <stdlib.h>

void combine(int arr1[], int n1, int arr2[], int n2, int **result) {
    *result = malloc((n1 + n2) * sizeof(int));

    int ind1 = 0;
    int ind2 = 0;
    int ind3 = 0;
    while (ind1 < n1 && ind2 < n2) {
        if (arr1[ind1] < arr2[ind2]) {
            (*result)[ind3++] = arr1[ind1++];
        } else {
            (*result)[ind3++] = arr2[ind2++];
        }
    }

    while (ind1 < n1) {
        (*result)[ind3++] = arr1[ind1++];
    }

    while (ind2 < n2) {
        (*result)[ind3++] = arr2[ind2++];
    }

}

void print_array(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[n - 1]);
}

int main(void) {
    int num = 1;
    {
        int n1 = 3;
        int n2 = 3;
        int arr1[] = {1, 3, 5};
        int arr2[] = {2, 4, 6};
        int *result;
        combine(arr1, n1, arr2, n2, &result);
        printf("Test %d\n", num++);
        printf("Expected:1 2 3 4 5 6\n");
        printf("Actual  :");
        print_array(result, n1 + n2);
        printf("\n");
    }

    {
        int n1 = 4;
        int n2 = 3;
        int arr1[] = {1, 2, 5, 9};
        int arr2[] = {11, 20, 24};
        int *result;
        combine(arr1, n1, arr2, n2, &result);
        printf("Test %d\n", num++);
        printf("Expected:1 2 5 9 11 20 24\n");
        printf("Actual  :");
        print_array(result, n1 + n2);
        printf("\n");
    }

    {
        int n1 = 3;
        int n2 = 5;
        int arr1[] = {2, 5, 9};
        int arr2[] = {4, 6, 24, 51, 55};
        int *result;
        combine(arr1, n1, arr2, n2, &result);
        printf("Test %d\n", num++);
        printf("Expected:2 4 5 6 9 24 51 55\n");
        printf("Actual  :");
        print_array(result, n1 + n2);
        printf("\n");
    }
}
