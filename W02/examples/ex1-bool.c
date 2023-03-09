/*
Objectives:
1. Use the bool 'datatype'
2. Use comparison operators (<, <=, >, >=, == , !=)
3, Use logical AND and OR operators (&&, ||)
*/

#include <stdio.h>
#include <stdbool.h> // this header library is only necessary if you want to declare boolean datatypes

int main(void){
    //bool x = true;
    printf("%d\n", true); // true == 1
    printf("%d\n", false); // false == 0
    int x = 3;
    printf("x > 3: %d\n", x > 3);
    printf("x >= 3: %d\n", x >= 3);
    printf("x < 3: %d\n", x > 3);
    printf("x <= 3: %d\n", x <= 3);
    printf("x == 3: %d\n", x == 3);
    printf("x != 3: %d\n", x != 3);

    //this is an illustration of how silly booleans in C are
    if('c')
        printf("'c' is true\n");
    if(21)
        printf("21 is true\n");
    if("else")
        printf("else is true\n");
    if(3.14159)
        printf("pi is true\n");
    if(!0)
        printf("0 is false\n");
}
