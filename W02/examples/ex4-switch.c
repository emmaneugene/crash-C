/* 
Learn to use the switch statement
 
switch (expression)
{
case  <constant-expression> :
    code 
    break;

default:
    break;
}
*/
#include <stdio.h>

int main(void){
    char color;
    printf("Enter color:");
    scanf("%c", &color);

    switch (color)
    {
    case 'R' :
        printf("Red\n");
        color = 'G';
        break; // you must insert a break at every point, otherwise the following lines of code will be executed as well
    case 'G' : 
        printf("Green\n");
        color = 'B';
        break;
    case 'B' :
        printf("Blue\n");
        color = 'Y';
        break;
    case 'Y' :
        printf("Yellow\n");
        color = 'R';
        break;
    default: // 'catch all' scenario.
        printf("invalid color\n");
    }
    printf("The color you entered is %c\n", color);
}