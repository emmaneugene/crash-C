// if, else if, else statements

#include <stdio.h>

int main(void){
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    if(n % 2 == 0 && n % 3 == 0 ){
        printf("n is divisible by 2 and 3\n");
    }
    else if(n % 2 == 0 || n % 3 == 0){
        printf("n is divisible by 2 or 3\n");
    }
    else{
        printf("n is not divisible by 2 or 3\n");
    }
}