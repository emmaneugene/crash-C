#include <stdio.h>
#include <string.h>

void trim(char *sentence) {
    // Find start
    char *ptr = sentence;
    while (*ptr == ' ') {
        ptr++;
    }
    
    // Trim the end
    int end = strlen(sentence);
    while (sentence[end - 1] == ' ') {
        end--;
    }
    sentence[end] = '\0';

    // Copy over
    while (*ptr != '\0') {
        *sentence++ = *ptr++;
    }
    *sentence = *ptr;
}
int main(void) {
    {
        char sentence[] = "    apple and orange";
        trim(sentence);
        printf("Test 1\n");
        printf("Expected:[apple and orange]\n");
        printf("Actual  :[%s]\n", sentence);
        printf("\n");
    }

    {
        char sentence[] = "apple and orange          ";
        trim(sentence);
        printf("Test 2\n");
        printf("Expected:[apple and orange]\n");
        printf("Actual  :[%s]\n", sentence);
        printf("\n");
    }

    {
        char sentence[] = "       apple and orange          ";
        trim(sentence);
        printf("Test 3\n");
        printf("Expected:[apple and orange]\n");
        printf("Actual  :[%s]\n", sentence);
    }
}