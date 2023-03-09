#ifndef __TEST_MODE__
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_and_replace(char *target, const char *find, const char substitute) {
    int len = strlen(find);

    while (*target) {
        for (int i = 0; i < len; i++) {
            if (find[i] == *target) {
                *target = substitute;
            }
        }
        target++;
    }
}
#endif

int main(void) {
    int test_id = 0;
    double score = 0;

    {
        char input[]    = "salt";
        char *find      = "t";
        char substitute = 'l';
        char expected[] = "sall";
        double worth_score = 2;

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Find:       ");
        printf("'%c'", find[0]);
        for (int i = 1; i < strlen(find); i++) {
            printf(", '%c'", find[i]);
        }
        printf("\n");
        printf("Substitute: '%c'\n", substitute);
        printf("Input:      %s\n", input);
        printf("Expected:   %s\n", expected);
        find_and_replace(input, find, substitute);
        printf("Actual:     %s\n", input);
        if (strcmp(input, expected) == 0) {
            score += worth_score;
            printf("Score:      %.1f/%.1f\n", worth_score, worth_score);
        } else {
            printf("Score:      0/%.1f\n", worth_score);
        }
        printf("\n");
    }

    {
        char input[]    = "salt";
        char *find      = "t0123";
        char substitute = 'l';
        char expected[] = "sall";
        double worth_score = 1;

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Find:       ");
        printf("'%c'", find[0]);
        for (int i = 1; i < strlen(find); i++) {
            printf(", '%c'", find[i]);
        }
        printf("\n");
        printf("Substitute: '%c'\n", substitute);
        printf("Input:      %s\n", input);
        printf("Expected:   %s\n", expected);
        find_and_replace(input, find, substitute);
        printf("Actual:     %s\n", input);
        if (strcmp(input, expected) == 0) {
            score += worth_score;
            printf("Score:      %.1f/%.1f\n", worth_score, worth_score);
        } else {
            printf("Score:      0/%.1f\n", worth_score);
        }
        printf("\n");
    }

    {
        char input[]    = "spaces are spaced out";
        char *find      = " ";
        char substitute = '_';
        char expected[] = "spaces_are_spaced_out";
        double worth_score = 1;

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Find:       ");
        printf("'%c'", find[0]);
        for (int i = 1; i < strlen(find); i++) {
            printf(", '%c'", find[i]);
        }
        printf("\n");
        printf("Substitute: '%c'\n", substitute);
        printf("Input:      %s\n", input);
        printf("Expected:   %s\n", expected);
        find_and_replace(input, find, substitute);
        printf("Actual:     %s\n", input);
        if (strcmp(input, expected) == 0) {
            score += worth_score;
            printf("Score:      %.1f/%.1f\n", worth_score, worth_score);
        } else {
            printf("Score:      0/%.1f\n", worth_score);
        }
        printf("\n");
    }

    {
        char input[]    = "spaces are spaced out";
        char *find      = "cs";
        char substitute = 'z';
        char expected[] = "zpazez are zpazed out";
        double worth_score = 1;

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Find:       ");
        printf("'%c'", find[0]);
        for (int i = 1; i < strlen(find); i++) {
            printf(", '%c'", find[i]);
        }
        printf("\n");
        printf("Substitute: '%c'\n", substitute);
        printf("Input:      %s\n", input);
        printf("Expected:   %s\n", expected);
        find_and_replace(input, find, substitute);
        printf("Actual:     %s\n", input);
        if (strcmp(input, expected) == 0) {
            score += worth_score;
            printf("Score:      %.1f/%.1f\n", worth_score, worth_score);
        } else {
            printf("Score:      0/%.1f\n", worth_score);
        }
        printf("\n");
    }

    printf("score,%s,1,%.1f\n", __FILE__, score);
}
