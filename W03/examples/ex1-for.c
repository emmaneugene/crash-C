#include <stdio.h>

/* 
Understand the 3 elements of a for-loop:
1. Initialisation of variable (need not be int, can be char or double as well)
2. Condition (if false, break out of the loop) - this implies that the loop will run forever is the condition is not made false
3. Increment

Understand the concept of variable scopes
(under which context variables are garbage collected)
 */

int main(void){
    int n;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("How many times would you like your name repeated?\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Hello, %s\n", name);
        // {} represents a scope
        // it is always a good practice to declare variable in the smallest scope possible
        // realise that the variable i is terminated once the loop exits.
    }

    // you can declare a variable outside a for loop and use it within the loop as well
    int j = 0;

    for (; j < 5; j++) {
        printf("hello, %d\n", j);
    }
}