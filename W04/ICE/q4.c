#include <stdio.h>

int main(void){
    int num;
    printf("Enter num:");
    scanf("%d", &num);

    int num_digits = 0;

    while (num > 0) {
        num_digits++;
        num /= 10;
    }

    printf("%d\n", num_digits);
}
