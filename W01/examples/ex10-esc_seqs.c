/* 
1. Understand the escape sequences in print functions

*/

#include <stdio.h>
int main(void){
    // \n creates a newline
    // \t creates a tab (8 spaces)
    printf("\tLet's C!\n");
    // \" can be used to print " normally
    printf("Let's \"C\"\n");
    // \\ can be used to print \ normally
    printf("Let's \\C\\\n");

    // \r or 'carriage return' returns to the leftmost side of the current line
    printf("Hello\rReplaced?\n");
}