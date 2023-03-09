#include <stdio.h>

int main(void){
    char c;
    printf("Enter letter:");
    scanf(" %c", &c);

    while ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        // Make our letters lowercase to simplify the cases
        if (c < 'a') {
            c += 'a' - 'A';
        }

        // Check whether c is a vowel or consonant
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                printf("vowel\n\n");
                break;
            default:
                printf("consonant\n\n");
        }

        printf("Enter letter:");
        scanf(" %c", &c);
    }
    printf("Bye bye\n");
}
