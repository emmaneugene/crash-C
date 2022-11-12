#include <stdio.h>

int main(void){
    int n1, n2;
    printf("Enter n1: ");
    scanf("%d", &n1);

    printf("Enter n2: ");
    scanf("%d", &n2);

    printf("%d + %d = %d\n", n1, n2, n1 + n2);
    printf("%d * %d = %d\n", n1, n2, n1 * n2);
    printf("%d / %d = %d\n", n1, n2, n1 / n2); // long division
}