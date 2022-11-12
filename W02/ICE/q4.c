#include <stdio.h>

int main(void){
    int weight; // declare variables
    double height;

    printf("Enter weight(kg):"); // get input
    scanf("%d", &weight);

    printf("Enter height(m)");
    scanf("%lf", &height);

    double bmi = weight / (height * height); // calculate BMI

    printf("BMI is %.6lf\n", bmi); 
    
    // go from largest to smallest value for BMI
    if (bmi >= 30) {
        printf("You are considered obese.\n");
    } else if (bmi >= 25) {
        printf("You are considered overweight.\n");
    } else if (bmi >= 18.5) {
        printf("You are considered normal.\n");
    } else {
        printf("You are considered underweight.\n");
    }

    /* 
    Test cases          Expected output
    -----------------------------------
    weight = 100        obese
    height = 1.80
    -----------------------------------
    weight = 80         overweight
    height = 1.75
    -----------------------------------
    weight = 60         normal
    height = 1.75
    -----------------------------------
    weight = 45         underweight
    height = 1.60
     */
}