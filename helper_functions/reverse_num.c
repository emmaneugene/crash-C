#include <stdio.h>

int reverse_num(int num) {
    // Takes in a number, positive or negative, and returns that number written backwards
    // If the number has trailing zeros, they will be eliminated
    // e.g. 9600 becomes 69
    int reversed_num = 0;

    while (num != 0) {
        reversed_num = reversed_num * 10 + num % 10;
        num /= 10;
    }
    return reversed_num;
}

int main(void) {
    printf("Number: 123\n");
    printf("Reverse: %d\n", reverse_num(123));

    printf("Number: -13001\n");
    printf("Reverse: %d\n", reverse_num(-13001));

    printf("Number: 12321\n");
    printf("Reverse: %d\n", reverse_num(12321));

    printf("Number: 9600\n");
    printf("Reverse: %d\n", reverse_num(9600));
}
