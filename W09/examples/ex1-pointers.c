/*
1. Declaring pointers
2. Address (&) operator to get the address of a variable in memory
3. The indirection (*) operator to get the value of an object referenced by a pointer
 */
#include <stdio.h>

// We can print out pointers to memory addresses

int main(void) {
    int n = 50;
    // '&' - gets the memory address
    printf("Address of variable :%p\n\n", &n);
    // '*' - dereferencing operator
    printf("Dereferenced memory address of n: %i\n\n", *&n);
    // We can chain the operators as much as we want
    printf("Chained address: %p\n\n", &*&*&n);
    printf("Chained dereference: %d\n\n", *&*&n);

    // Initialise a pointer to n
    // Pointer stores the ADDRESS of an INT variable
    int *ptr = NULL; //
    ptr = &n;
    // Printing the value of pointer
    printf("Pointer: %p\n\n", ptr);
    // We can print the memory address of the pointer itself, but this value will be different from the address of the int variable
    printf("Address of pointer: %p\n\n", &ptr);

    printf("Single dereferenced pointer:%p -> %i\n\n", ptr, *ptr);

    // You can also initialise a pointer to a pointer, like so
    int **dbl_ptr =  NULL; // Declaration
    dbl_ptr = &ptr; // Assignment
    printf("Double dereferenced pointer:%p -> %p -> %i\n\n",dbl_ptr, *dbl_ptr, **dbl_ptr);

    // Can you do it a third time? Certainly. You can keep making pointers to pointers. Pointerception!!
    int ***trpl_ptr = NULL; // Declaration
    trpl_ptr = &dbl_ptr; // Assignment
    printf("Triple dereferenced pointer:%p -> %p -> %p -> %i\n\n", trpl_ptr, *trpl_ptr, **trpl_ptr, ***trpl_ptr);

    // What about multiple declarations on the same line?

    // In the following case a is a pointer, but b is an integer
    int* a, b;

    // If we want to do multiple pointer declarations, we should do the following
    int *ptr_a, *ptr_b;
}
