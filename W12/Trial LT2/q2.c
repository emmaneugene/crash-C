#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool valid_email(char string[]) {
    int prefix_count = 0;
    while (*string != '@') {
        prefix_count++;
        string++;
    }

    // Check for trailing @smu.edu.sg
    return (prefix_count > 0 && (strcmp(string, "@smu.edu.sg") == 0));
}

int main(void) {
    char email[40];

    printf("Please enter your SMU email address: ");
    scanf("%s", email);

    while (!valid_email(email)) {
        printf("Invalid!\n");
        printf("Please enter your SMU email address: ");
        scanf("%s", email);
    }

    printf("Thanks!\n");
}