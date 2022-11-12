#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));

    int num1 = rand() % 10;
    int num2 = rand() % 10;
    int num3 = rand() % 10;

    printf("Press <enter> key to start");
    getchar();

    printf("*****************\n");
    printf("** %d ** %d ** %d **\n", num1, num2, num3);
    printf("*****************\n");

    if (num1 == num2 && num2 == num3) {
        printf("** Jackpot!! **\n");
    } else if (num1 == num2 || num1 == num3 || num2 == num3) {
        printf("** 2 of a kind **\n");
    } else {
        printf("** Try again! **\n");
    }
    
    /* 
    Test cases          Expected output
    -----------------------------------
    8                   Jackpot
    8
    8
    -----------------------------------
    2                   2 of a kind
    6
    6
    -----------------------------------
    1                   Try again
    7
    4
    -----------------------------------
     */
}
