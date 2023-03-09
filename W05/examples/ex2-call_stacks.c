/*
Objectives:
1. Understand what happens in memory when a function is invoked
2. Understand the LIFO principle of stacks
 */

#include <stdio.h>

void do_y();

void do_x(int x){
    x++;
    do_y(x);
    printf("%d\n", x);
}

void do_y(int x){
    printf("%d\n", x);
}


int main(void){
    int x = 3;
    /* When a function is invoked, a separate pool of memory is set aside
    all the variables within a function exist within the scope of the function itself
    therefore any change in the value of x within do_x() will not change the value of x within the scope of main()
    */
    do_x(x);
    /*
    Stacks follow the principle of LIFO (last in first out) the idea being that pushing adds a stack to the top, while popping removes a stack from the top
     */

    // Here, we still have  x = 3
    do_y(x);
}
