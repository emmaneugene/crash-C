#include <stdio.h>
#include <string.h>

void print_dancing_string(char *string, char spot) {
    int shift = 0;

    if (spot == 'M') {
        shift = 1;
    } else if (spot == 'B') {
        shift = 2;
    }

    int len = strlen(string);
    int repeat;

    for (int line = 0; line < 3; line++) {
        repeat = 4;
        if (line == 1) {
            repeat = 2;
        }

        printf("|");
        for (int i = 0; i < len; i++) {
            if (i % repeat == (line + shift) % repeat) {
                printf("%c", string[i]);
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
}

int main(void) {
    {
        printf("Test 1\n");
        printf("Expected:\n");
        printf("|a|\n");
        printf("| |\n");
        printf("| |\n");
        printf("Actual  :\n");
        print_dancing_string("a", 'T');
        printf("\n");
    }

    {
        printf("Test 2\n");
        printf("Expected:\n");
        printf("|a   e   i|\n");
        printf("| b d f h |\n");
        printf("|  c   g  |\n");
        printf("Actual  :\n");
        print_dancing_string("abcdefghi", 'T');
        printf("\n");
    }

    {
        printf("Test 3\n");
        printf("Expected:\n");
        printf("| b   f   |\n");
        printf("|a c e g i|\n");
        printf("|   d   h |\n");
        printf("Actual  :\n");
        print_dancing_string("abcdefghi", 'M');
        printf("\n");
    }

    {
        printf("Test 4\n");
        printf("Expected:\n");
        printf("|  c   g  |\n");
        printf("| b d f h |\n");
        printf("|a   e   i|\n");
        printf("Actual  :\n");
        print_dancing_string("abcdefghi", 'B');
        printf("\n");
    }

    {
        printf("Test 5\n");
        printf("Expected:\n");
        printf("||\n");
        printf("||\n");
        printf("||\n");
        printf("Actual  :\n");
        print_dancing_string("", 'B');
        printf("\n");
    }
}