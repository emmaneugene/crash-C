/*
How do we create an array in main through a helper function function?
 */
#include <stdio.h>
#include <stdlib.h>

void change_array(int **arr, int n) {
    *arr =  malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        (*arr)[i] = i + 1;
    }
}

int main(void) {
    int *arr = NULL;
    change_array(&arr, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }
}
