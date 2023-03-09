/*
Objectives:
1. Be able to define a function
2. Understand control flow when a function is invoked
 */

#include <stdio.h>

// Function takes in various inputs and RETURNS one output
// In C, when you don't have any input/output, you can put specify a VOID datatype instead
void print_fruits(void){
    printf("apple\norange\npear\n");
}

// Even though you can get away with not declaring variable inputs to a function, you should not do that
int multiply_by_2(num){
    return num * 2;
}

int main(void){
    print_fruits();
    printf("---\n");
    print_fruits();

    int num;
    printf("Enter num:");
    scanf("%d", &num);
    printf("%d multiplied by 2 is %d\n", num, multiply_by_2(num));
}
