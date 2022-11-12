#include <stdio.h>
#include <math.h>

int main(void){
    double amt_dollars; // declare variables
    int amt_cents;

    printf("Enter amount:"); // get input
    scanf("%lf", &amt_dollars);

    // convert amount to cents (int datatype)
    amt_cents = (int)round(amt_dollars * 100);
    printf("Amount in cents: %d\n", amt_cents);


    // slowly subtract the denominations from highest to lowest
    if (amt_cents >= 100) {
        printf("Number of 1$: %d\n", amt_cents / 100);
        amt_cents = amt_cents % 100;
    }
    if (amt_cents >= 50) {
        printf("Number of 50c: %d\n", amt_cents / 50);
        amt_cents = amt_cents % 50;
    }
    if (amt_cents >= 20) {
        printf("Number of 20c: %d\n", amt_cents / 20);
        amt_cents = amt_cents % 20;
    }
    if (amt_cents >= 10) {
        printf("Number of 10c: %d\n", amt_cents / 10);
        amt_cents = amt_cents % 10;
    }
    if (amt_cents >= 5) {
        printf("Number of 5c: %d\n", amt_cents / 5);
        amt_cents = amt_cents % 5;
    }
    if (amt_cents >= 1) {
        printf("Number of 1c: %d\n", amt_cents / 1);
    }

    /* 
    Test cases          Expected output
    -----------------------------------
    5.1                 $1: 5
                        10c: 1
    -----------------------------------
    4.75                $1: 4
                        50c: 1
                        20c: 1
                        5c: 1
    -----------------------------------
    6.78                $6: 6
                        50c: 1
                        20c: 1
                        5c: 1
                        3c: 3
    -----------------------------------
     */
}