#include <stdio.h>

int main(void){
    char ch; // declare variables

    printf("Enter char:"); // get input
    scanf("%c", &ch);

    if (ch >= '0' && ch <= '9') {
        printf("%c is a digit\n", ch); // check for digit
    } else if (ch >= 'a' && ch <= 'z') {
        printf("%c is a lowercase letter\n", ch); // check for lowercase
    } else if (ch >= 'A' && ch <= 'Z') {
        printf("%c is a uppercase letter\n", ch); // check for uppercase
    } else {
        printf("%c is a special character\n", ch); // remaining cases
    }

    /* 
    Test cases          Expected output
    -----------------------------------
    0                   digit
    -----------------------------------
    \t                  special character
    -----------------------------------
    e                   lowercase letter
    -----------------------------------
    R                   uppercase letter
     */
}