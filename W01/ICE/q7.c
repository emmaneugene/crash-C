#include <stdio.h>

int main(void){
    int weight;
    double height;
    printf("Enter weight(kg): ");
    scanf("%d", &weight);
    printf("Enter height(m): ");
    scanf("%lf", &height);
    printf("BMI is %.15lf\n", weight / (height * height) );
}