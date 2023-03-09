#include <stdio.h>

int get_num_length(int num) {
    // Takes in a positive or negative number, and returns its length
    if (num < 0) {
        num *= -1;
    }

    int count = 0;
    while (num > 0) {
        num /= 10;
        count++;
    }
}
