#include <stdio.h>

#define SIZE_FIVE 5
#define SIZE_ONE 1

void merge_sort(int values[], int start, int end) {
    if (end - start == 1) {
        return;
    } 

    // Sort subarrays
    int middle = (end - start) / 2;
    merge_sort(values, start, start + middle);
    merge_sort(values, start + middle, end);

    // Merge subarrays
    int temp_arr[end - start];
    int idx1 = start;
    int idx2 = start + middle;
    int idx3 = 0;

    while (idx1 < start + middle && idx2 < end) {
        temp_arr[idx3++] = (values[idx1] < values[idx2]) ? values[idx1++] : values[idx2++];         
    }

    while (idx1 < start + middle) {
        temp_arr[idx3++] = values[idx1++];
    }

    while (idx2 < end) {
        temp_arr[idx3++] = values[idx2++];
    }

    // Copy to values[]
    for (int i = 0; i < end - start; i++) {
        values[start + i] = temp_arr[i];
    }
}

void print_array(int values[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}
int main(void) {
    {
        int values[SIZE_FIVE] = {7, 3, 6, 5, 1};
        merge_sort(values, 0, SIZE_FIVE);
        printf("Expected:1 3 5 6 7\n");
        printf("Actual  :");
        print_array(values, SIZE_FIVE);
        printf("\n");
    }

    {
        int values[] = {2, 3, 5, 6, 7};
        merge_sort(values, 0, SIZE_FIVE);
        printf("Expected:2 3 5 6 7\n");
        printf("Actual  :");
        print_array(values, SIZE_FIVE);
        printf("\n");
    }

    {
        int values[SIZE_ONE] = {1};
        merge_sort(values, 0, SIZE_ONE);
        printf("Expected:1\n");
        printf("Actual  :");
        print_array(values, SIZE_ONE);
        printf("\n");
    }

    {
        int values[] = {9, 10, -1, 6, 3, 56, 20, 1};
        merge_sort(values, 0, sizeof(values) / sizeof(int));
        printf("Expected:-1 1 3 6 9 10 20 56\n");
        printf("Actual  :");
        print_array(values, sizeof(values) / sizeof(int));
        printf("\n");
    }
}