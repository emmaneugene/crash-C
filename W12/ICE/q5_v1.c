#include <stdio.h>
#include <string.h>

void print_dancing_string(char *string, char spot) {
    int len = strlen(string);

    // Assume we print from the top
    int top_start = 0;
    int mid_start = 1;
    int bot_start = 2;

    if (spot == 'M') {
        top_start = 1;
        mid_start = 0;
        bot_start = 3;

    } else if (spot == 'B') {
        top_start = 2;
        mid_start = 1;
        bot_start = 0;
    }

    // Top
    char top_row[len + 1];
    for (int  i = 0; i < len; i++) {
        if (i == top_start) {
            top_row[i] = string[i];
            top_start += 4;
        } else {
            top_row[i] = ' ';
        }
    }
    top_row[len] = '\0';

    // Middle
    char mid_row[len + 1];
    for (int  i = 0; i < len; i++) {
        if (i == mid_start) {
            mid_row[i] = string[i];
            mid_start += 2;
        } else {
            mid_row[i] = ' ';
        }
    }
    mid_row[len] = '\0';

   char bot_row[len + 1];
   for (int  i = 0; i < len; i++) {
        if (i == bot_start) {
            bot_row[i] = string[i];
            bot_start += 4;
        } else {
            bot_row[i] = ' ';
        }
    }
    bot_row[len] = '\0';

    printf("|%s|\n", top_row);
    printf("|%s|\n", mid_row);
    printf("|%s|\n", bot_row);
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
