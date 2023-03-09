/*
1. Understand basic arithmetic operators in C (+, -, /, %, *)
2. Understand how mixed type expressions are evalated (e.g int / int = float)
3. Understand the rules of precedence for order of operations (BODMAS)
   1. ()
   2. * / %
   3. + -
   4. =
   note that there is no power operator by default in C

4. Understand associativity rules for operators of the same precedence
   In general, operators are read from left to right by default
   EXCEPT for assignment(=), which is read from right to left
 */
#include <stdio.h>

int main(void){
    int x = 5;
    int y = 2;

    printf("%d + %d = %d\n", x, y, x + y);
    printf("%d - %d = %d\n", x, y, x - y);
    printf("%d / %d = %d (when datatypes are int)\n", x, y, x / y);
    printf("%d / %d = %f (when at least one datatype is float)\n", x, y, (double)x / y); // typecasting
    printf("%d * %d = %d\n", x, y, x * y);
    printf("%d %% %d = %d\n", x, y, x % y);

    //this illustrates the need to pay close attention to operation precedence
    double d = 7/2;
    printf("%.1lf\n", d);

}
