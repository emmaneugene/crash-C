#include <stdio.h>
#include <string.h>

void print_triangle(char *string, char fill) {
    int len = strlen(string);

    int sum = 0;

    for (int i = 1; sum < len; i++) {
        for (int j = 0; j < i; j++) {
            if (sum < len) {
                printf("%c", string[sum++]);
            } else {
                printf("%c", fill);
            }
        }
        printf("\n");
    }
}

int main(void) {

    {
        printf("Test case 1:\n");
        print_triangle("abcdefghijk", '#');
    }

    {
        printf("Test case 2:\n");
        print_triangle("a", '#');
    }

    {
        printf("Test case 3:\n");
        print_triangle("hello, world", '-');
    }
}
