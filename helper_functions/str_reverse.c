#include <stdio.h>

void reverse_string(char string[]) {
    // Reverses an entire string
    int len = strlen(string);
    char temp;
    
    for (int i = 0; i < len / 2; i++) {
        temp = string[i];
        string[i] = string[len - 1 - i];
        string[len - 1 - i] = temp;
    }
}

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