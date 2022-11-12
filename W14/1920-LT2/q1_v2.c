/**
 * Name : Emmanuel Oh Eu-Gene
 * Email: emmanueloh.2019@sis.smu.edu.sg
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_and_replace(char *target, const char *find, const char substitute) {
    int len1 = strlen(target);
    int len2 = strlen(find);

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (find[j] == target[i]) {
                target[i] = substitute;
            }
        }
    }
}

int main(void) {
    int test_id = 0;

    {
        char input[] = "pootato";
        char *find = "a";
        char substitute = 'o';
        char expected[] = "poototo";
        // test 1
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
        printf("\n");
    }

    {
        char input[] = "i love you 3000";
        char *find = "30";
        char substitute = '9';
        char expected[] = "i love you 9999";
        // test 2
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
        printf("\n");
    }

    {
        char input[] = "code";
        char *find = "code";
        char substitute = 'z';
        char expected[] = "zzzz";
        // test 3
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
        printf("\n");
    }

    {
        char input[] = "I love cooking, my korkor, and my dog";
        char *find = ",";
        char substitute = ' ';
        char expected[] = "I love cooking  my korkor  and my dog";
        // test 4
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
        printf("\n");
    }

    {
        char input[] = "Courage! Do not be afraid! Just a few questions left!";
        char *find = "1234567890";
        char substitute = 'Z';
        char expected[] = "Courage! Do not be afraid! Just a few questions left!";
        // test 5
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
        printf("\n");
    }
}
