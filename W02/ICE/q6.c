#include <stdio.h>

int main(void){
    int side_a; // declare variables
    int side_b;
    int side_c;

    printf("Enter side a:"); // get input
    scanf("%d", &side_a);

    printf("Enter side b:");
    scanf("%d", &side_b);
    
    printf("Enter side c:");
    scanf("%d", &side_c);

    if (side_a + side_b > side_c && side_a + side_c > side_b && side_b + side_c > side_a) {
        printf("It is a valid triangle.\n");
    } else {
        printf("It is an invalid triangle.\n");
    }
    
    /* 
    Test cases          Expected output
    -----------------------------------
    7                   valid
    10
    5
    -----------------------------------
    0                   invalid
    10
    0
    -----------------------------------
    10                  invalid
    20
    30 
    -----------------------------------
     */
}