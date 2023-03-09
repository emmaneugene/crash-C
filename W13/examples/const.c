// the const keyword can and should be user

#include <stdio.h>

int main(void) {
    int x = 3;
    int y = 4;
    // ptr1 is pointer to a constant
    // pointer is mutable, but data is immutable
    const int *ptr1 = &x;
    ptr1 = &y; // valid
    *ptr1 = 5; // invalid

    // ptr2 is a constant pointer to an integer
    // pointer is immutable, but data is mutable
    int * const ptr2 = &y;
    *ptr2 = 5; // valid
    ptr2 = &x; // invalid

    // const pointer to a constant integer
    int z = 5;
    const int *const ptr3 = &z;
}
