/* 
Distinction between passing by reference and passing values
 */

#include <stdio.h>

void do_x(int x) {
    x = 4; // whatever is done here is garbage-collected, since nothing is returned
}

void do_y(int y[]) {
    y[0] = 9;
}

void do_z(const int z[]) {
    // passing with a const keyword makes the array read-only
    printf("%d\n", z[0]);
}

int main(void) {
    int x = 3;
    do_x(x);
    printf("%d\n", x);
    /* 
    x (int datatype) is passed as a value. this means that the variable x within do_x() has a different memory
    address compared to x within main()
    */

    int y[3] = {3, 4, 5};
    do_y(y);
    for (int i = 0; i < 3; i++) {
        printf("%d\n", y[i]);
    }
    /* 
    what does this illustrate?
    when arrays are passed into a function, they are passed as reference(address in memory) instead of as values.
    the array within do_y() has the same address as the one in main()
    implication? any changes you make to array within the context of a function will update the array within main()
    as well
     */

    int z[3] = {3, 4, 5};
    do_z(z);
    for (int i = 0; i < 3; i++) {
        printf("%d\n", z[i]);
    }
}