#include <stdio.h>

// Now that we have understood pointers, we can look back at arrays with some interesting conclusions

int main(void) {
    int array[] = {1, 2, 3, 4, 5};
    int *ptr = array;
    // array++;  This is NOT allowed. We cannot change the starting point of an array
    ptr++; // This is allowed
}