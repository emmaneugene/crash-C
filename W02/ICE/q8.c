#include <stdio.h>

int main(void){
    int mth; // declare variables

    printf("Enter month as a number:"); // get input
    scanf("%d", &mth);

    if (mth < 1 || mth > 12) { // first check for correct input
        printf("Enter a number between 1 and 12 only.\n");
    } else {
        switch(mth){ // then find out how many days
        case 2:
            printf("There are 28 days in this month.\n");
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("There are 30 days in this month.\n");
            break;
        default:
            printf("There are 31 days in this month.\n");
        }
    }

    /*
    Test cases          Expected output
    -----------------------------------
    2                   28 days
    -----------------------------------
    3                   31 days
    -----------------------------------
    4                   30 days
    -----------------------------------
    14                  invalid
     */
}
