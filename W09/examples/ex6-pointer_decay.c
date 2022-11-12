#include <stdio.h>

void get_array_size(int numbers[]) {
    // within the function, numbers is now a pointer and no longer an array
    // pointer takes up 4 bytes
    // int takes up 2 bytes
    // therefore no matter what you pass in , sizeof(numbers) / sizeof(int) = pointer
    printf("Within get_array_size()\n");
    printf("Size of numbers[]: %lu bytes\n", sizeof(numbers));
    printf("Size of int      : %lu bytes\n", sizeof(int));
    printf("Size of numbers[] / int: %lu \n", sizeof(numbers) / sizeof(int) );
    
}

int main(void) {
    // arrays "decay" into a pointer when passed into a function
    // therefore, we should pass in the length of an array into the function, 
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8};
    printf("Within main()\n");
    printf("Size of numbers[]: %lu bytes\n", sizeof(numbers));
    printf("Size of int      : %lu bytes\n", sizeof(int));
    printf("Size of numbers[] / int: %lu \n\n", sizeof(numbers) / sizeof(int) );
    get_array_size(numbers);
}