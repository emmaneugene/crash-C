/* 
Understand the concept of a do while loop

|    while               |    do while            |
|-------------------------------------------------|
|while (condition)       |    do something        |
|do something            |    while (condition)   |

a do while loop guarantees at least one iteration of code execution
 */

#include <stdio.h>

int main(void){
    char response = 'N';

    do {
        printf("Do you love me? ");
        scanf(" %c", &response);
    } while (response != 'Y'&& response != 'y');
    
    printf("Thank you!\n");
}