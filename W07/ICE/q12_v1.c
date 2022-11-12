#include <stdio.h>
#include <string.h>

void reverse_words(char sentence[]) {
    int len = strlen(sentence);

    // Create a new array to store reversed words
    char reversed_words[len];

    // Create an index, word_start and word_end to track where you are
    int index = 0;
    int word_start = 0;
    int word_end = 0;

    // Stop once we index the end of the string
    while (index < len) {
        // Get next word_end
        while (sentence[index + 1] != ' ' && sentence[index + 1] != 0) {
            index++;
        }
        word_end = index;
        // Put next word at the back of reversed_words[]
        for (int i = word_start; i <= word_end; i++) {
            reversed_words[len - 1 - word_end + (i - word_start)] = sentence[i];
        }
        // Put in the space
        index++;
        if (sentence[index] == ' ') {
            reversed_words[len - 1 - index] = ' ';
        }
        // Get next word_start
        index ++;
        word_start = index;
    }

    // Copy reversed_words[] into sentence[]
    for (int i = 0; i < len; i++) {
        sentence[i] = reversed_words[i];
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
