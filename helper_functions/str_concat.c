#include <stdio.h>
#include <string.h>

void lengthen_string(char string[], int num) {
    // Include in main(), since arrays cannot be returned with the exception of malloc()
    // Create a new array which increases the length by len
    int len = strlen(string);
    char extended_string[len + num];

    for (int i = 0; i < len; i++) {
        extended_string[i] = string[i];
    }

    for (int j = len; j < len + num; j++) {
        extended_string[j] = 0;
    }
}

void concat_string(char string1[], char string2[]) {
    // Concatenates string2[] to string1[]
    // When passed in, string1[] should have enough spare memory space to accomodate string2[]
    int start = 0;
    while (string1[start] != 0) {
        start++;
    }
    
    int len = strlen(string2);
    for (int i = 0; i < len; i++) {
        string1[start + i] = string2[i];
    }
}