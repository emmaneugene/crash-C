#include <stdio.h>

int main(void){
    int smallest_num; // declare variables
    int largest_num;
    int n1;
    int n2;
    int n3;
    
    printf("Enter n1:"); // get input
    scanf("%d", &n1);

    printf("Enter n2:");
    scanf("%d", &n2);
    
    printf("Enter n3:");
    scanf("%d", &n3);

    smallest_num = n2; 
    largest_num = n1; // assume this at first

    if (n1 < n2) {
        smallest_num = n1; 
        largest_num = n2; // if first comparison is false, swap values
    }

    if (smallest_num > n3) {
        smallest_num = n3; //comparing smallest value with n3
    }

    if (largest_num < n3) {
        largest_num = n3; //comparing largest value with n3
    }

    printf("Smallest is %d\nLargest is %d\n", smallest_num, largest_num);

    /* 
    Test cases          Expected output
    -----------------------------------
    n1 = 77             smallest: 77
    n2 = 88             largest: 99
    n3 = 99
    -----------------------------------
    n1 = 10             smallest: 10
    n2 = 10             largest: 10
    n3 = 10
    -----------------------------------
    n1 = 55             smallest: 55
    n2 = 90             largest: 90
    n3 = 55
    -----------------------------------
    n1 = 40             smallest: 40
    n2 = 62             largest: 62
    n3 = 62
    */
}
