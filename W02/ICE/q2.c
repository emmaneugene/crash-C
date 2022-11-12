#include <stdio.h>

int main(void){
    int num; // declare variables

    printf("Enter num:"); // get input
    scanf("%d", &num);

    printf("%d is %s\n", num, num % 2 == 0 ? "even" : "odd");
    
    /* 
    Test cases          Expected output
    -----------------------------------
    num = 0             even
    -----------------------------------
    num = 7             odd
    -----------------------------------
    num = 4             even
     */
}