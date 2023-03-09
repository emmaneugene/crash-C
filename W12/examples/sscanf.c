#include <stdio.h>

/*
 Understand how to use scanf()
 sscanf() is to scanf() just as sprintf() is to printf()
 if sprintf() allows you to store values into a string, then sscanf() allows you to read values from a string
 */

int main(void) {
    int sum = 0;

    char *num1 = "101";
    sscanf(num1, "%d", &sum);
    printf("%d\n", sum);

    char *num2 = "023";
    sscanf(num2, "%d", &sum);
    printf("%d\n", sum);

    char *num3 = "   10";
    sscanf(num3, "%d", &sum);
    printf("%d\n", sum);
}
