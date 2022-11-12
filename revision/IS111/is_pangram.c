#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_pangram(char *sentence) {
    int char_tracker[26] = {0};
    
    int temp = 0;
    while (*sentence != '\0') {
        if(isalpha(*sentence)) {
            temp = tolower(*sentence) - 'a';
            char_tracker[temp]++;
        }
        sentence++;
    }

    for (int i = 0; i < 26; i++) {
        if (char_tracker[i] == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    {
        printf("Test case 1:\n");
        char *string = "abcdefghijk";
        printf("String : %s\n", string);
        printf("Is pangram? %s\n", is_pangram(string) ? "true" : "false");
    }

    {
        printf("Test case 2:\n");
        char *string = "the quick brown fox jumps over the lazy dog";
        printf("String : %s\n", string);
        printf("Is pangram? %s\n", is_pangram(string) ? "true" : "false");
    }

    {
        printf("Test case 3:\n");
        char *string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        printf("String : %s\n", string);
        printf("Is pangram? %s\n", is_pangram(string) ? "true" : "false");
    }
}