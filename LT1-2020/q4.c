#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_infinite_number(int num) {
    if (num == 1)
        return false;
    if (num == 4)
        return true;
    
    int new_num = 0;
    while (num != 0) {
        new_num += pow(num % 10, 2);
        num /= 10;
    }
    return is_infinite_number(new_num);
}

// ------------------------TESTS------------------------

int main(void) {
    printf("%s\n", is_infinite_number(1) ? "true" : "false");

    printf("%s\n", is_infinite_number(2) ? "true" : "false");

    printf("%s\n", is_infinite_number(144) ? "true" : "false");
}