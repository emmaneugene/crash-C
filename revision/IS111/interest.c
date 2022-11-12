#include <stdio.h>
#include <math.h>

int main(void) {
    int deposit;
    double interest;
    int freq;
    int yrs;

    printf("Initial Deposit: ");
    scanf("%d", &deposit);

    printf("Annual interest rate: ");
    scanf("%lf", &interest);
    interest /= 100;

    printf("Annual Compound Frequency: ");
    scanf("%d", &freq);

    printf("Num years: ");
    scanf("%d", &yrs);

    printf("Amount after %d years is %.2lf\n", yrs, deposit * pow(1 + interest / freq, (double)freq * yrs));
}