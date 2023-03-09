/*
Recap: Pass by value vs pass by reference
 */

#include <stdio.h>

void swap_by_value(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void swap_by_reference(int *x, int *y) {
    // This function does not receive the values, it receives pointers to the 2 values
    // The pointers themselves are not changed, they are made to store different int values
    // Addresses remain the same, but values stored in the address are reassigned
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(void) {
    int x = 3;
    int y = 8;

    printf("Before swap_by_value: x = %d, y = %d\n", x, y);
    printf("Memory addresses: x = %p, y = %p\n", &x, &y);
    swap_by_value(x, y);
    printf("After swap_by_value: x = %d, y = %d\n", x, y);
    printf("Memory addresses: x = %p, y = %p\n", &x, &y);

    printf("Before swap_by_reference: x = %d, y = %d\n", x, y);
    printf("Memory addresses: x = %p, y = %p\n", &x, &y);
    // When we want to pass variables by reference, we need to use the & operator to get the MEMORY ADDRESS
    swap_by_reference(&x, &y);
    printf("After swap_by_reference: x = %d, y = %d\n", x, y);
    printf("Memory addresses: x = %p, y = %p\n", &x, &y);
}
