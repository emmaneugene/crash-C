/*
1. Define a 2-dimensional array
2. Pass a 2-d array into a function
 */

#include <stdio.h>

int main(void) {
    // Declaring a 2-dimensional array is the same as declaring an array of arrays
    // Take note that the second dimension NEEDS to be specified (i.e. number of columns)
    // This same rule applies during function calls as well
    // Visualisation
    //      [0] [1] [2]
    //     +---+---+---+
    // [0] | 2 | 3 | 3 |
    //     +---+---+---+
    // [1] | 4 | 5 | 7 |
    //     +---+---+---+
    //
    int arr[][3] = {
        {2, 3, 3},
        {4, 5, 7}
        };
    // Print middle element of first row
    printf("%d\n", arr[0][1]);
    // Print last element of last row
    printf("%d\n\n", arr[1][2]);

    // Can we declare 3d arrays? Certainly
    // Generalising, we need to specify all dimensions except the first one
    int arr_3d[][2][2] = {
        {{1, 2}, {3, 4}},
        {{5, 6}, {7, 8}}
        };
    // First element in 3d array
    printf("{%d, %d}\n", arr_3d[0][0][0], arr_3d[0][0][1]);
    // Last element in 3d array
    printf("{%d, %d}\n", arr_3d[1][1][0], arr_3d[1][1][1]);

}
