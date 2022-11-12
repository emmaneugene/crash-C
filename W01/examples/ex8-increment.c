/* 
1. Understand unary operators
2. Understand the special case behind unary operators
 */
#include <stdio.h>

int main(void){
    int x = 1;
    // to increment x by 1, we have several methods:
    // 1. x = x + 1
    // 2. x += 1
    // 3. x++
    // 4. ++x
    //*5. x -=-1

    // a special case occurs when assigning the value of one variable to another
    // in this case, y takes the incremented value of x
    int y = ++x;
    printf("in the case of ++x: y = %d, x = %d\n", y, x);
    // in this case, y takes the value of x before it is incremented
    x = 1;
    y = x++;
    printf("in the case of x++: y = %d, x = %d\n", y, x);

    // ** TAKE NOTE **
    int f = 2;
    int g = f++;
    printf("%d\n", x+1); // x+1, x++ and ++x all produce different results
    printf("%d %d\n", x, y);
}