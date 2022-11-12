#include <stdio.h>

int main(void){
    double sales; // declare variables
    int rate;

    printf("Enter the amount of monthly sales($):"); // get input
    scanf("%lf", &sales);

    if (sales >= 18000) {
        rate = 18;
    } else if (sales >= 15000) {
        rate = 15;
    } else if (sales >= 10000) {
        rate = 10;
    } else {
        rate = 5;
    }

    printf("Commission rate for the monthly sale of %.2lf is %d%%\n", sales, rate);
    printf("The monthly pay for the salesperson is %.2lf\n", (2000 + sales * rate / 100));

    /* 
    Test cases          Expected output
    -----------------------------------
    
    -----------------------------------

    -----------------------------------

    -----------------------------------
     */
}