/*
1. Understand that each variable has a specific address in memory
2. Learn how to use the scanf function to read from stdin
 */

#include <stdio.h>

int main(void){
    // all variables have an address in memory
    // each variable is a container with ONLY 1 value

    // getting user to input an int
    int x;
    double y;
    printf("Enter an integer x: ");
    scanf("%d", &x); // ampersand to specify memory location
                     // but why must we specify memory location?
    printf("Enter an float y: ");
    scanf("%lf", &y);

    printf("Integer x is %d\n", x);
    printf("Float y is %lf\n", y);

    //getting user to input a char
    char ch1, ch2;
    printf("Enter character 1: ");
    scanf(" %c", &ch1); // NOTE: having a space first tells scanf to ignore whitespaces and newlines
                        // otherwise once you hit enter the next scanf will take \n as the intended character
    printf("Enter character 2: ");
    scanf(" %c", &ch2);

    printf("Character 1 is %c\n", ch1);
    printf("Character 2 is %c\n", ch2);

    //getting user to input a string(an array of characters)
    char str1[20], str2[20]; // getting user to input a string
    printf("Enter name: ");
    scanf("%s", str1); // why is there no need for ampersand here?

    printf("Enter email:");
    scanf("%s", str2);

    printf("Entered name: %s\n", str1);
    printf("Entered email: %s\n", str2);

    // Scanning strings with spaces
    char sentence[50];
    printf("Enter sentence:");
    scanf(" %50[^\n]", sentence);

    printf("Sentence:\n%s\n", sentence);
}
