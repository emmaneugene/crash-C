#include <stdio.h>

int main(void){
    int num;
    printf("Enter num:");
    scanf("%d", &num);

    // Get largest power of 2 less than or equal to num
    // At the same time, track the multiplier (or the power)
    int largest_power = 1;
    int multiplier = 0;
    while (largest_power * 2 <= num) {
        largest_power *= 2;
        multiplier++;
    }

    // Now go back. For every deduction that can be made, print '1'
    for (int i = multiplier; i >= 0; i--) {
        if (num >= largest_power) {
            printf("1");
            num -= largest_power;
        } else {
            printf("0");
        }
        largest_power /= 2;
    }
    printf("\n");
}
