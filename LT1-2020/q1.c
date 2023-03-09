#include <stdio.h>

void sum_of_neighbours(int numbers[], int length) {
    if (numbers == NULL || length <= 1)
        return;

    int tmp[length];

    tmp[0] = numbers[0] + numbers[1];

    for (int i = 1; i < length - 1; i++) {
        tmp[i] = numbers[i-1] + numbers[i] + numbers[i+1];
    }

    tmp[length-1] = numbers[length-2] + numbers[length-1];

    for (int i = 0; i < length; i++) {
        numbers[i] = tmp[i];
    }
}

void print_array(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// ------------------------TESTS------------------------

int main(void) {
    int arr1[] = {23};
    printf("Expected: 23\n");
    printf("Actual  : ");
    sum_of_neighbours(arr1, sizeof(arr1)/sizeof(int));
    print_array(arr1, sizeof(arr1)/sizeof(int));

    int arr2[] = {11, 22};
    printf("Expected: 33 33\n");
    printf("Actual  : ");
    sum_of_neighbours(arr2, sizeof(arr2)/sizeof(int));
    print_array(arr2, sizeof(arr2)/sizeof(int));


    int arr3[] = {10, 20, 30, 40};
    printf("Expected: 30 60 90 70\n");
    printf("Actual  : ");
    sum_of_neighbours(arr3, sizeof(arr3)/sizeof(int));
    print_array(arr3, sizeof(arr3)/sizeof(int));
}
