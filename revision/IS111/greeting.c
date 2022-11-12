#include <stdio.h>

int main(void) {
    char name[30];
    char gend = '\0';

    printf("Enter name :");
    scanf("%20[^\n]", name);

    printf("Enter gender (M or F) :");
    scanf(" %c", &gend);

    printf("Welcome, ");

    if (gend == 'M') {
        printf("Mr ");
    } else if (gend == 'F') {
        printf("Miss ");
    }

    printf("%s!\n", name);
}