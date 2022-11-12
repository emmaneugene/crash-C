/*
1. What is a variable
2. Declaration of a variable
3. Assign a value to a variable using assignment operator(=)
4. Display a value using printf()
5. Understand that code is executed in a sequential manner
*/


#include <stdio.h>

int main(void){
    int x; // declaration
    x = 3; // assignment
    int y = 4 ; // initialisation
    // use %i to format a string to display an integer datatype
    printf("the value of x is %i\n", x);
    // %d can also be used
    printf("the value of x is %i and the value of y is %d\n", x, y);
}