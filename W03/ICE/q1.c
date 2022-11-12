#include <stdio.h>
#include <math.h>

int main(void) { 
    double deposit;
    printf("Initial deposit(P):");
    scanf("%lf", &deposit);

    double yearly_rate;
    printf("Annual Interest Rate (in %%, r):");
    scanf("%lf", &yearly_rate);
    yearly_rate /= 100; // 0.01 for 1%
    
    double freq;
    printf("Annual Compound Frequency (1 to 12, n):");
    scanf("%lf", &freq);
    
    double years;
    printf("Num years (t):");
    scanf("%lf", &years);

    // calculate amount
    double amount = deposit * pow((1 + yearly_rate / freq), freq * years); 
    printf("Amount after %.0lf years is %.2lf", years, amount);
}