/*
1. Use pointers to store struct addresses
2. Note the struct datatypes are passed by value between functions
3. Use pointers to pass by reference
 */

#include <stdio.h>

typedef struct {
    int x;
    int y;
} point;

void reassign_by_value(point coords) {
    coords.x = 5;
    coords.y = 6;
}

void reassign_by_reference(point* coords) {
    coords->x = 5;
    coords->y = 6;
}

int main(void) {
    // Declare a point
    point coords = {1, 2};

    // Declare a pointer to that point
    point* ptr = &coords;

    /*
    Operator precedence:
    HIGH PRECEDENCE
    . - Member access via object name
    * - Indirection operator
    LOW PRECEDENCE
    */

    printf("Coordinates: (%d, %d)\n", (*ptr).x,  (*ptr).y);

    // Alternatively, you can use the -> operator to access a member of an object within a pointer
    printf("Coordinates: (%d, %d)\n", ptr->x,  ptr->y);

    // When passing by value, the values of x and y are not changed within main()
    reassign_by_value(coords);
    printf("After reassigning by reference, coordinates: (%d, %d)\n", ptr->x,  ptr->y);

    // When passing by reference, the values of x and y do change within main()
    reassign_by_reference(&coords);
    printf("After reassigning by reference, coordinates: (%d, %d)\n", ptr->x,  ptr->y);
}
