#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 Creates a copy of an existing array using malloc()
*/
int *arr_copy(int *arr, int size) {
    int *copy = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        copy[i] = arr[i];
    }

    return copy;
}


void add_to_combination(int *combi, int combi_size, int *arr, int idx, int arr_size, int sum, bool *valid_combi_ptr) {
    // Base case: exhuasted all a possible array elements
    if (idx == arr_size) {
        free(combi);
        return;
    }

    int val = arr[idx];

    // If adding current value completes sum, print out the combination
    if (val == sum) {
        printf("(");
        for (int i = 0; i < combi_size; i++) {
            printf("%d, ", combi[i]);
        }
        printf("%d)\n", val);

        if (!(*valid_combi_ptr)) {
            *valid_combi_ptr = true;
        }
    }

    // If adding current value is still less than sum,
    // - create a copy of existing combination
    // = add current value to copy
    // - subtract value from sum
    //  call recursive function to look at next element
    if (val < sum) {
        int *combi_copy = arr_copy(combi, arr_size);
        combi_copy[combi_size] = val;
        add_to_combination(combi_copy, combi_size+1, arr, idx+1, arr_size, sum-val, valid_combi_ptr);
    }

    // Move on with current combination, look at next element in the array
    return add_to_combination(combi, combi_size, arr, idx+1, arr_size, sum, valid_combi_ptr);
}

void get_sum_combinations(int *arr, int size, int sum) {
    int *combi = calloc(size, sizeof(int));
    for(int i = 0; i < size; i++) {
        combi[i] = 0;
    }

    bool valid_combi = false;

    add_to_combination(combi, 0, arr, 0, size, sum, &valid_combi);

    if (!valid_combi) {
        printf("-None-\n");
    }
}

int main(void) {

    {
        printf("Test case 1\n");
        int arr[] = {4, 3, 2, 1};
        int sum = 10;

        printf("Expected: \n");
        printf("(4, 3, 2, 1)\n");

        printf("Actual  : \n");
        get_sum_combinations(arr, sizeof(arr)/sizeof(int), sum);
    }

    {
        printf("\n\nTest case 2\n");
        int arr[] = {4, 3, 2, 1};
        int sum = 5;

        printf("Expected: \n");
        printf("(4, 1)\n");
        printf("(3, 2)\n");

        printf("Actual  : \n");
        get_sum_combinations(arr, sizeof(arr)/sizeof(int), sum);


    }

    {
        printf("\n\nTest case 3\n");
        int arr[] = {17, 5};
        int sum = 11;

        printf("Expected: \n");
        printf("-None-\n");

        printf("Actual  : \n");
        get_sum_combinations(arr, sizeof(arr)/sizeof(int), sum);
    }
}
