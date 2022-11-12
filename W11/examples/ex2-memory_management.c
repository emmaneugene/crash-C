/* 
1. Use malloc()/calloc() to dynamically allocate memory
   malloc() - used to allocate space for a memory block
   calloc() - used to allocate space for an array in memory
2. Use free() to de-allocate memory

 */

#include <stdio.h>
#include <stdlib.h>

int* malloc_array(int n) {
    // conventionally, you cannot pass a pointer to an array created within a helper function, as the pool of memory is garbage collected once the function exits
    // the pointer address returned will not point to anything useful, it might even be restricted memory
    // malloc() creates dynamic memory on the HEAP instead of the STACK, which remains even after the function exits
    int *ptr = malloc(n * sizeof(int)); // in the heap
    return ptr;
}

int* calloc_array(int n) {
    // calloc() works similar to malloc, but takes into 2 parameters instead
    // in a sense, calloc() presumes you want an array, while malloc() just gives you memory space
    int *ptr = calloc(n, sizeof(int));
    return ptr;
}

int main(void) {
    int *malloc_arr = malloc_array(5);
    for (int i = 0; i < 5; i++) {
        printf("%d\n", malloc_arr[i]);
    }
    printf("\n");

    int *calloc_arr = calloc_array(5);
    for (int i = 0; i < 5; i++) {
        printf("%d\n", calloc_arr[i]);
    }

    // it is good practice to clear free dynamically allocated memory space after you've finished using it
    free(malloc_arr);
    free(calloc_arr);
}