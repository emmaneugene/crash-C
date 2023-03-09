#include <stdio.h>

int main(void){
    int num;
    printf("Enter number:");
    scanf("%d", &num);
    int n1 = num / 10000;
    int n2 = num % 10000 / 1000;
    int n3 = num % 1000 / 100;
    int n4 = num % 100 / 10;
    int n5 = num % 10;
    printf("%d + %d + %d + %d + %d = %d\n", n1, n2, n3, n4, n5, n1+n2+n3+n4+n5);
}
