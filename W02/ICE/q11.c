#include <stdio.h>
#include <stdbool.h>

int main(void){
    char gend; // declare variables
    int age;
    double premium;

    printf("Enter your gender (M or F) :"); // get input
    scanf("%c", &gend);

    printf("Enter your age: ");
    scanf("%d", &age);

    bool is_male = (gend == 'M' || gend == 'm') ? true : false;

    // check cases in ascending order of age
    if (age < 25) {
        premium = is_male ? 20.50 : 30.60;
    } else if (age < 30) {
        premium = is_male ? 30.40 : 50.70;
    } else if (age < 65) {
        premium = is_male ? 60.70 : 99.80;
    } else {
        premium = is_male ? 70.70 : 120.30;
    }

    printf("Your premium is $%.2lf\n", premium);

    /*
    Test cases          Expected output
    -----------------------------------
    F                   50.70
    25
    -----------------------------------
    M                   70.70
    80
    -----------------------------------
    F                   99.80
    40
    -----------------------------------
     */
}
