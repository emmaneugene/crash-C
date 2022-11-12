#include <stdio.h>
#include <string.h>

void reverse_substring(char string[], int start, int end) {
    // Reverses a string's contents from string[start] to string[end]
    int len = end - start + 1;
    char temp;

    for(int i = 0; i < len / 2; i++) {
        temp = string[start + i];
        string[start + i] = string[end - i];
        string[end - i] = temp;
    }
}

void reverse_words(char sentence[]) {
    // Step 1: Reverse the string entirely
    int len = strlen(sentence);
    reverse_substring(sentence, 0, len - 1);
    // Step 2: Reverse each word you find
    int index = 0;
    int word_start = 0;
    int word_end = 0;
    
    while (index < len) {
        // Get next word_end
        while (sentence[index + 1] != ' ' && sentence[index + 1] != 0) {
            index++;
        }
        word_end = index;
        // Swap characters from word_start to word_end
        reverse_substring(sentence, word_start, word_end);
        // Get next word_start
        index += 2;
        word_start = index;
    }
}

int main(void) {
    {
        printf("Test 1\n");
        char sentence[] = "apple and orange";
        reverse_words(sentence);
        printf("Expected:orange and apple\n");
        printf("Actual  :%s\n", sentence);
        printf("\n");
    }

    {
        printf("Test 2\n");
        char sentence[] = "I sell seashell by the seashore";
        reverse_words(sentence);
        printf("Expected:seashore the by seashell sell I\n");
        printf("Actual  :%s\n", sentence);
        printf("\n");
    }

    {
        printf("Test 3\n");
        char sentence[] = "I";
        reverse_words(sentence);
        printf("Expected:I\n");
        printf("Actual  :%s\n", sentence);
        printf("\n");
    }

    {
        printf("Test 4\n");
        char sentence[] = "";
        reverse_words(sentence);
        printf("Expected:><\n");
        printf("Actual  :>%s<\n", sentence);
        printf("\n");
    }

    {
        printf("Test 4\n");
        char sentence[] = "I love it when I finish the last question in the practice";
        reverse_words(sentence);
        printf("Expected:practice the in question last the finish I when it love I\n");
        printf("Actual  :%s\n", sentence);
        printf("\n");
    }
}