/*
Strings
1. How to declare them
2. End of line character '\0'
3. strlen() function
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    // this is one way (and the most explicit way) to declare a string
    // take note that the ascii character for '\0' has the ASCII integer 0 - you can use both
    char apple[6] = {'a', 'p', 'p', 'l', 'e', '\0'};
    for (int i = 0; apple[i] != '\0'; i++) {
        printf("%c", apple[i]);
    }
    printf("\n");

    // use the strlen() function from <string.h> to find the length of a string
    printf("string length: %d\n", strlen(apple));
    printf("%s\n", apple);

    // this is another way to declare a string
    char grape[] = "grape";
    printf("%s\n", grape);

    // make sure you add another element to include the null character '\0', otherwise weird things happen
    char banana[7] = "banana";
    printf("%s\n", banana);

    // this does not work, because we used double inverted commas
    char pear[] = {"p", "e", "a", "r", "\0"};
    printf("%s\n", pear);

    // take note that we cannot compare strings in C like we do for primitive datatypes. Instead, we must compare each and every element on the string, or use the function strcmp() from string.h

    char name[] = "Emman";

    // strcmp returns 0 if both of the strings are the same, or a nonzero value if they are different
    if (strcmp(name, "Emman") == 0) {
        printf("strings are the same\n");
    }
}
