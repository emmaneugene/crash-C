/*
There is a difference in the way you declare strings
 */
#include <stdio.h>

int main(void) {
    char *word = "car"; // string literal is READ ONLY, and immutable

    // the string literal is stored in a different place in memory, and any attempts to change characters in *word will result in an error

    char word_2[] = "car"; // is an array, and is mutable

    // arrays "decay" into a pointer when passed into a function
    // therefore, we should pass in the length of an array into the function,

    word[2] = 'b'; // this is NOT ALLOWED, as string literals cannot be modified
    word_2[2] = 'b';

    printf("%s\n", word);
    printf("%s\n", word_2);
}
