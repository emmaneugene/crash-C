#include <stdio.h>

int main(void) {
    int arr[] = {1, 2, 3};

    int *ptr1[3] = {&arr[0], &arr[1], &arr[2]}; // an array of pointers

    int (*ptr2)[3] = &arr; // memory address of an array
    // same as int **ptr2 = &arr

    // Print out pointer addresses
    for (int i = 0; i< 3; i++) {
        printf("%p -> %d\n", ptr1[i], *ptr1[i]);
    }

    // Compare and contrast
    for (int i = 0; i < 3; i++) {
        printf("%p -> %d\n", &(*ptr2)[i], (*ptr2)[i]);
    }
}