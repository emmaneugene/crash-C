#include <stdio.h>
#include <math.h>

int main(void){
    int num;
    printf("Enter num:");
    scanf("%d", &num);

    int binary_num = 0;
    int i = 0;

    while (num != 0) {
        binary_num += (num % 2) * pow(10, i);
        num /= 2;
        i++;
    }
    printf("%d\n", binary_num);
}
