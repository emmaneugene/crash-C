#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *get_max_sum_sublist(int numbers[], int n, int k) {
    if (k > n) {
        return NULL;
    }

    int *max_sublist = &numbers[0];

    int max_sum = 0;
    for (int i = 0; i < k; i++) {
        max_sum += numbers[i];
    }

    int next_sum = 0;

    for (int i = 1; i < n - k; i++) {
        next_sum = 0;
        for (int j = 0; j < k; j++) {
            next_sum += numbers[i + j];
        }
        if (next_sum > max_sum) {
            max_sum = next_sum;
            max_sublist = &numbers[i];
        }
    }
    return max_sublist;
}

void print_array(int *arr, int n) {
    if (arr == NULL) {
        printf("NULL\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", *arr++);
    }
    printf("\n");
}
int main(void) {
    {
        int input[] = {11, 3, 9, 8, 13, 0, 12};
        int k = 4;
        int *result = get_max_sum_sublist(input, sizeof(input) / sizeof(int), k);
        printf("Expected:3 9 8 13\n");
        printf("Actual  :");
        print_array(result, k);
        printf("\n");
    }

    {
        int input[] = {11, 3, 9, 8, 7, 2};
        int k = 3;
        int *result = get_max_sum_sublist(input, sizeof(input) / sizeof(int), k);
        printf("Expected:9 8 7\n");
        printf("Actual  :");
        print_array(result, k);
        printf("\n");
    }
    {
        int input[] = {11, 3};
        int k = 3;
        int *result = get_max_sum_sublist(input, sizeof(input) / sizeof(int), k);
        printf("Expected:NULL\n");
        printf("Actual  :");
        print_array(result, k);
        printf("\n");
    }
}
