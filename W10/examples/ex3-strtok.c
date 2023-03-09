#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char sentence[] = "C is such a fun language";

    /*
    strtok() takes a string and tokenises it - splitting the string into multiple sub-strings
    the very first time you want to tokenise a string, you pass in the string itself
    subsequently if you pass in NULL, the function refers to a static pointer to get the remaining tokens of the string
    */

    char *token_ptr = strtok(sentence, " ");

    while (token_ptr != NULL) {
        printf("%s \n", token_ptr);
        token_ptr = strtok(NULL, " ");
    }

    printf("Sentence: %s\n", sentence);

}
