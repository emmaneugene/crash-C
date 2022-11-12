#include <stdio.h>

int main(void){
    int n1; // declare variables
    int n2;
    
    printf("Enter n1:"); // get input
    scanf("%d", &n1);
    
    printf("Enter n2:");
    scanf("%d", &n2);

    if (n1 != 0 && n2 % n1 == 0) { // if n1 == 0, break out of the loop immediately, or you will divide by 0
        printf("%d is a factor of %d\n", n1, n2);
    } else {
        printf("%d is not a factor of %d\n", n1, n2);
    }

    /* 
    Test cases          Expected output
    -----------------------------------
    n1 = 3              is a factor
    n2 = 12
    -----------------------------------
    n1 = 5              is not a factor
    n2 = 12
    -----------------------------------
    n1 = 12             is not a factor
    n2 = 5
    -----------------------------------
    n1 = 10             is a factor
    n2 = 0
    -----------------------------------
    n1 = 0             is NOT a factor**
    n2 = 10
    */
}