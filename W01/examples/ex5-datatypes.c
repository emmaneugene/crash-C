/*
1. Understand the few basic datatypes (int, double, char)
2. Remember the format placeholders to use for each datatype
*/

/*
There 4 main primitive datatypes in C:
1. char - character as encoded by ASCII
2. int - integer or whole number
3. float/double - floating point number or decimal
4. void - stores nothing
*/
#include <stdio.h>

int main(void){
    /*
    primitive datatype: char
    size: 1 byte (8 bits)
    value range(s): 0 to 255 or -128 to 127
    format placeholder(s): %c
    notes: that char datatypes are effectively integers encoded by ASCII, and you can do arithmetic with them as you would with ints
    */
    char c = 'A';
    printf("for char datatype 'A':\n");
    printf("formatted char: %c\nformatted int: %d\nformatted float: %lf\n\n", c, c, c); // legal C, prints out ASCII encoding of 'c'

    /*
    primitive dataype: int
    size: 2 bytes (16 bits) or 4 bytes (32 bits)
    value range(s): do the math, for signed and unsigned ints
    format placeholder(s): %d, %i - there are more you can read up on
    notes: when assigning a floating point value to an int datatype , C simply removes everything past the decimal point
    */
    int x = 65;
    printf("for int datatype 65:\n");
    printf("formatted char: %c\nformatted int: %d\nformatted float: %lf\n\n", x, x, x);


    /*
    primitive dataype: float/double
    size: 2 bytes (16 bits) or 4 bytes (64 bits)
    value range(s): more precise from float > double > long double, read up to learn more
    format placeholder(s): %lf(for float and double) , %f(for float only) - there are more you can read up on
    notes: floating point values can never be completely precise, due to memory constraints
    */
    float y = 65.141592653589793238;
    printf("for float datatype 65.141592653589793238:\n");
    printf("formatted char: %c\nformatted int: %d\nformatted float: %lf\n\n", y, y ,y);

}
