#include <stdio.h>

int main(void){
    int a,b;
    float c,d;
    a = 15;
    b = a / 2;
    printf("%d\n", b);
    printf("%3d\n", b); // this adds leading spaces (to fill up 3 characters)
    printf("%.4d\n", b); // this adds leading numbers (to fill up 3 characters)

    c = 15.3;
    d = c / 3;
    printf("%.5f\n",d);
}