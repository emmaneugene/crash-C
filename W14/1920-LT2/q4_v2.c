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
    int idx  = 0;
    int word_start = 0;
    int word_end = 0;

    // Find "word"
    while (idx < len) {
        // Get next word_end
        while (sentence[idx + 1] != ' ' && sentence[idx + 1] != '\0') {
            idx++;
        }
        word_end = idx;

        // Copy word into a new string and pass to correct_word()
        char word[word_end - word_start + 2];
        for (int i = 0; i < word_end - word_start + 1; i++) {
            word[i] = sentence[word_start + i];
        }
        word[word_end - word_start + 1] = '\0';

        correct_word(word, dict, n);

        // Copy corrected word
        for (int i = 0; i < word_end - word_start + 1; i++) {
            sentence[word_start + i] = word[i];
        }

        // Next word start
        idx += 2;
        word_start = idx;
    }

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
    int char_array[26] = {0};

    while (*str1) {
        char_array[*str1 - 'a']++;
        str1++;
    }
    
    while (*str2) {
        char_array[*str2 - 'a']--;
        str2++;
    }

    for (int i = 0; i < 26; i++) {
        if (char_array[i] != 0) {
            return false;
        }
    }
    return true;
}

void correct_word(char *word, char *dict[], int n) {
    int len = 0;
    for (int i = 0; i < n; i++) {
        if (is_anagram(word, dict[i])) {
            // Change word
            len = strlen(word);
            for (int j = 0; j < len; j++) {
                word[j] = dict[i][j];
            }
            return;
        }
    }
}