#include <stdio.h>

int main(void){
    char c;
    printf("Enter letter:");
    scanf(" %c", &c);

    while ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        // Make our letters lowercase to simplify the conditions
        if (c < 'a') {
            c += 'a' - 'A';
        }
        
        // Check whether c is a vowel or consonant
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            printf("vowel\n\n");
        } else {
            printf("consonant\n\n");
        }

        printf("Enter letter:");
        scanf(" %c", &c);
    }
    printf("Bye bye\n");
}