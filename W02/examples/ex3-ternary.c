/* 
Understand how the ternary operator works 
(boolean ? <value if True> : <value if False>)
the ternary operator can be used in the place of a basic if-else statement, if you are evaluating one bool
 condition
*/ 

#include <stdio.h>

int main(void){
    int score;
    printf("Enter score out of 100:");
    scanf("%d", &score);

    printf("%s\n", score < 50 ? "Fail" : "Pass");

    int x = 2;
    printf(x == 3 ? "True\n" : "False\n");
    printf(x = 3 ? "True\n" : "False\n"); // take note of this case!!

    x == 2 ? printf("x == 2\n") : printf("x != 2\n"); // you can put functions into the cases too
}