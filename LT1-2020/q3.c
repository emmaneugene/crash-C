#include <stdio.h>

int get_num_length(int num) {
    int len = 1;
    while (num > 10) {
        num /= 10;
        len++;
    }
    return len;
}

int extract(int num, int start, int end) {
    int len = get_num_length(num);
    
    int start_rmv_count = len - start;
    int start_multiplier = 1;
    for (int i = 0; i < start_rmv_count; i++) {
        start_multiplier *= 10;
    } 
    num %= start_multiplier;

    int end_rmv_cnt = len - end;
    for (int i = 0; i < end_rmv_cnt; i++) {
        num /= 10;
    }

    return num;
}

// ------------------------TESTS------------------------

int main(void) {
    printf("%d\n", extract(123456, 2, 5));

    printf("%d\n", extract(123456, 3, 4));

    printf("%d\n", extract(123456, 3, 7));
}