#include <stdio.h>

int main(void){
    double income; // declare variables
    double tax_payable;

    printf("Enter personal income :"); // get input
    scanf("%lf", &income);

    // calculate for descending values of income
    if (income > 200000) {
        tax_payable = 21150 + (income - 200000) * 0.2;
    } else if (income > 160000) {
        tax_payable = 13950 + (income - 160000) * 0.18;
    } else if (income > 120000) {
        tax_payable = 7950 + (income - 120000) * 0.15;
    } else if (income > 80000) {
        tax_payable = 3350 + (income - 80000) * 0.115;
    } else if (income > 40000) {
        tax_payable = 550 + (income - 40000) * 0.07;
    } else if (income > 30000) {
        tax_payable = 200 + (income - 30000) * 0.035;
    } else if (income > 20000) {
        tax_payable = (income - 20000) * 0.02;
    } else {
        tax_payable = 0;
    }

    printf("Tax payable: $%.1lf\n", tax_payable);

    /*
    Test cases          Expected output
    -----------------------------------
    350 000             51150.0
    -----------------------------------
    100 000             5650.0
    -----------------------------------
    28 000              160.0
    -----------------------------------
    12 000              0.0
     */
}
