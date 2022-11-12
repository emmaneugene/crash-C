#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generate_code(char *code) {
    srand(time(0));
    
    for (int i = 0; i < 4; i++) {
        switch (rand() % 6)
        {
        case 0:
            code[i] = 'R';
            break;
        case 1:
            code[i] = 'Y';
            break;
        case 2:
            code[i] = 'B';
            break;
        case 3:
            code[i] = 'O';
            break;
        case 4:
            code[i] = 'G';
            break;
        case 5:
            code[i] = 'V';
            break;    
        }
    }
}

bool match(char *code, char *guess) {
    return (strcmp(code, guess) == 0);
}

bool valid_guess(char *guess) {
    while (*guess != '\0') {
        switch (*guess) {
            case 'R':
            case 'Y':
            case 'B':
            case 'O':
            case 'G':
            case 'V':
                break;
            default:
                return false;
        }
        guess++;
    }

    return true;
}

int exact_matches(char *code, char *guess) {
    int count = 0;

    while (*code != '\0') {
        if (*code++ == *guess++) {
            count++;
        }
    }

    return count;
}

int partial_matches(char *code, char *guess) {
    int exact = exact_matches(code, guess);
    int len = strlen(code);
    int count = 0;

    char guess_copy[len];
    strcpy(guess_copy, guess);
    
    
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (code[i] == guess_copy[j]) {
                count++;
                guess_copy[j] = '\0';
                break;
            }
        }
    }

    return count - exact;
}

int main(void) {
    char code[5] = {0};
    generate_code(code);

    int count = 1;

    char guess[5];    
    printf("Enter 4-letter guess(R, O, Y, G, B, V):");
    scanf("%s", guess);

    while (!match(code, guess)) {
        if (!valid_guess(guess)) {
            printf("Invalid colors(%s)!\n\n", guess);
        } else {
            printf("%d exact matches, %d partial matches\n\n", exact_matches(code, guess), partial_matches(code, guess));
        }
        printf("Enter guess:");
        scanf("%s", guess);
        count++;
    }

    printf("You guessed the key: %s\n", code);
    printf("It took you %d guesses\n", count);
}