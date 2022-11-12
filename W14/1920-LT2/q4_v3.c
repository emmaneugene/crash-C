/**
 * Name : Emmanuel Oh Eu-Gene
 * Email: emmanueloh.2019@sis.smu.edu.sg
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_anagram(char *str1, char *str2);

void correct_word(char *word, char *dict[], int n);

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

int main(void) {
    int test_id = 0;

    {
        char input[] = "nma";
        char expected[] = "man";
        char *dict[] = {"not", "hot", "quick", "math", "likes",
                        "wolverine", "drinks", "soju", "pizza",
                        "wingstop", "iron", "man", "eats", "potato"};
        // Test 1
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Input:    %s\n", input);
        printf("Expected: %s\n", expected);
        autocorrect(input, sizeof(dict) / sizeof(char *), dict);
        printf("Actual:   %s\n", input);
        printf("\n");
    }

    {
        char input[] = "winelover likse zzipa";
        char expected[] = "wolverine likes pizza";
        char *dict[] = {"not", "hot", "quick", "math", "likes",
                        "wolverine", "drinks", "soju", "pizza",
                        "wingstop", "iron", "man", "eats", "potato"};
        // Test 2
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Input:    %s\n", input);
        printf("Expected: %s\n", expected);
        autocorrect(input, sizeof(dict) / sizeof(char *), dict);
        printf("Actual:   %s\n", input);
        printf("\n");
    }

    {
        char input[] = "rino man lskie stopwing";
        char expected[] = "iron man likes wingstop";
        char *dict[] = {"not", "hot", "quick", "math", "likes",
                        "wolverine", "drinks", "soju", "pizza",
                        "wingstop", "iron", "nori", "man", "eats", "potato"};

        // Test 3
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Input:    %s\n", input);
        printf("Expected: %s\n", expected);
        autocorrect(input, sizeof(dict) / sizeof(char *), dict);
        printf("Actual:   %s\n", input);
        printf("\n");
    }

    {
        char input[] = "pootato drinks juso";
        char expected[] = "pootato drinks soju";
        char *dict[] = {"not", "hot", "quick", "math", "likes",
                        "wolverine", "drinks", "soju", "pizza",
                        "wingstop", "iron", "man", "eats", "potato"};
        // Test 4
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Input:    %s\n", input);
        printf("Expected: %s\n", expected);
        autocorrect(input, sizeof(dict) / sizeof(char *), dict);
        printf("Actual:   %s\n", input);
        printf("\n");
    }

    {
        char input[] = "halp y u do dis";
        char expected[] = "halp y u do dis";
        char *dict[] = {"not", "hot", "quick", "math", "likes",
                        "wolverine", "drinks", "soju", "pizza", "wingstop", "iron", "man", "eats", "potato"};
        // Test 5
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Input:    %s\n", input);
        printf("Expected: %s\n", expected);
        autocorrect(input, sizeof(dict) / sizeof(char *), dict);
        printf("Actual:   %s\n", input);
        printf("\n");
    }
}

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