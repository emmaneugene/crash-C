/*
1. What is a structure in C
2. Structure declaration
3. Typedef
4. Inserting values
5. Extracting values
 */

#include <stdio.h>

// Coordinates of a point on a 2d graph
struct point {
    int x;
    int y;
}; // Important to suffix a structure declaration with a semicolon

// The typedef keyword allows us to declare using the alias of a struct, rather than specifying the datatype each time
typedef struct {
    char* name;
    char* address;
    char* number;
} contact;

int main(void) {
    // Suppose we want to save a point p with coordinates (2,3)
    struct point p;
    p.x = 2;
    p.y = 3;

    printf("Coordinates are: (%d, %d)\n", p.x, p.y);

    // Alternatively, we can use the same syntax as with array initialisation to save values into a struct
    contact emman = {"Emmanuel", "Toa Payoh", "91457278"};

    printf("Name: %s\nAddress: %s\nNumber: %s\n", emman.name, emman.address, emman.number);
}
