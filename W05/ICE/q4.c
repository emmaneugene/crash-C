#include <stdio.h>

int get_num_holes(int n){
    int num_holes = 0;
    int next_digit;

    while (n > 0) {
        next_digit = n % 10;
        switch (next_digit) {
            case (0):
            case (4):
            case (6):
            case (9):
                num_holes += 1;
                break;
            case (8):
                num_holes += 2;
                break;
        }
        n /= 10;
    }

    return num_holes;
}

int main(void) {
    {
        printf("Test 1\n");
        int result = get_num_holes(1208);
        printf("Expected:3\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 2\n");
        int result = get_num_holes(12357);
        printf("Expected:0\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 3\n");
        int result = get_num_holes(4690);
        printf("Expected:4\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 4\n");
        int result = get_num_holes(888);
        printf("Expected:6\n");
        printf("Actual  :%d\n\n", result);
    }
}
