#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    char is_playing = 'Y';

    // Loop for continuing the game
    while (is_playing == 'Y' || is_playing == 'y') {
        srand(time(0));
        int answer = rand() % 100 + 1;

        int guess;
        int attempts = 0;

        // Loop for user's guesses
        do {
            printf("Enter your guess(1 to 100) :");
            scanf("%d", &guess);

            if (guess > answer) {
                printf("High! Try again\n\n");
            } else if (guess < answer) {
                printf("Low! Try again\n\n");
            }

            attempts++;
        } while (guess != answer);

        printf("Congrats!\n\nYou guessed in %d attempts\n\nDo you want to play again? ", attempts);
        scanf(" %c", &is_playing);

        // Keep prompting the user until a valid input is entered
        while (is_playing != 'Y' && is_playing != 'y' && is_playing != 'N' && is_playing != 'n') {
            printf("Invalid input!\n\nDo you want to play again? ");
            scanf(" %c", &is_playing);
        }
    }

    printf("Bye!\n\n");
}