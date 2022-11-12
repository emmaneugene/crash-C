#ifndef __TEST_MODE__
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_anagram(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 != len2) {
        return false;
    }

    int char_array[26] = {0};

    for (int i = 0; i < len1; i++) {
        char_array[str1[i] - 'a']++;
        char_array[str2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (char_array[i] != 0) {
            return false;
        }
    }
    return true;
}

void correct_word(char *word, char *dict[], int n) {
    
    for (int i = 0; i < n; i++) {
        if (is_anagram(word, dict[i])) {
            strcpy(word, dict[i]);
            return;
        }
    }
}

void autocorrect(char *sentence, int n, char *dict[]) {
    int len = strlen(sentence);
    char *word_start = sentence;

    for (int i = 0; i < len; i++) {
        if (sentence[i] == ' ') {
            sentence[i] = '\0';
            correct_word(word_start, dict, n);
            sentence[i] = ' ';
            word_start = &sentence[i + 1];
        }
    }
    correct_word(word_start, dict, n);
}
#endif

int main(void) {
    int test_id = 0;
    double score = 0;

    {
        double score_worth   = 2;
        double score_awarded = 0;

        char input[] = "snam";
        char expected[] = "mans";
        char *dict[] = { "mans", "not", "hot" };

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Input:    %s\n", input);
        printf("Expected: %s\n", expected);
        autocorrect(input, sizeof(dict)/sizeof(char *), dict);
        printf("Actual:   %s\n", input);
        printf("\n");

        if (strcmp(input, expected) == 0) {
            score_awarded = score_worth;
        } else {
            score_awarded = 0;
        }
        score += score_awarded;

        printf("Score: %.1f/2.0\n", score_awarded);
        printf("\n");
    }

    {
        double score_worth   = 2;
        double score_awarded = 0;

        char input[] = "sayt storng";
        char expected[] = "stay strong";
        char *dict[] = { "stay", "strong" };

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Input:    %s\n", input);
        printf("Expected: %s\n", expected);
        autocorrect(input, sizeof(dict)/sizeof(char *), dict);
        printf("Actual:   %s\n", input);
        printf("\n");

        if (strcmp(input, expected) == 0) {
            score_awarded = score_worth;
        } else {
            score_awarded = 0;
        }
        score += score_awarded;

        printf("Score: %.1f/2.0\n", score_awarded);
        printf("\n");
    }

    {
        double score_worth   = 1;
        double score_awarded = 0;

        char input[] = "atou outa tauo lock";
        char expected[] = "auto auto auto lock";
        char *dict[] = { "auto", "toua"};

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Input:    %s\n", input);
        printf("Expected: %s\n", expected);
        autocorrect(input, sizeof(dict)/sizeof(char *), dict);
        printf("Actual:   %s\n", input);
        printf("\n");

        if (strcmp(input, expected) == 0) {
            score_awarded = score_worth;
        } else {
            score_awarded = 0;
        }
        score += score_awarded;

        printf("Score: %.1f/1.0\n", score_awarded);
        printf("\n");
    }

    printf("score,%s,4,%.1f", __FILE__, score);
}
