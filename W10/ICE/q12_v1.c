#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void scramble(char *scrambled, int start, int end) {

    srand(time(0));
    int rand_index;
    char temp;

    // Use Durstenfeld/Knuth version to randomly shuffle
    for (int i = start; i < end; i++) {

        // Make sure characters are shuffled as far as possible
        do {
            rand_index = rand() % (end - i) + i;
        } while (end - i > 1 && rand_index == i);

        temp = scrambled[i];
        scrambled[i] = scrambled[rand_index];
        scrambled[rand_index] = temp;
    }
}

void scramble_sentence(char *original, char *scrambled) {
    // Copy original to scrambled
    int len = strlen(original);

    for (int i = 0; i < len; i++) {
        scrambled[i] = original[i];
    }
    scrambled[len] = '\0';

    // Scramble words
    int start = 0;
    int end = 0;

    while (start < len) {
        // Find the end of the next word
        end = start;
        while (isalpha(scrambled[end])) {
            end++;
        }

        // Scramble all except first and last letters
        scramble(scrambled, start + 1, end - 1);

        // Find the start of the next word, if any
        start = end;
        while(!isalpha(scrambled[start]) && start < len) {
            start++;
        }
    }
}

int main(void) {
    {
        char orig[] = "This is a sentence with 7 tokens";
        char scrambled[35];
        scramble_sentence(orig, scrambled);
        printf("Test 1\n");
        printf("Original :%s\n", orig);
        printf("Scrambled:%s\n", scrambled);
        printf("\n");
    }

    {
        char orig[] = "C is peculiar in a lot of ways, but it, like many other successful things, has a certain unity of approach that stems from development in a small group.";
        char scrambled[155];
        scramble_sentence(orig, scrambled);
        printf("Test 2\n");
        printf("Original :%s\n", orig);
        printf("Scrambled:%s\n", scrambled);
    }

    {
        char orig[] = "Oh, and while the king was looking down, the jester stole his thorny crown. The courtroom was adjourned; no verdict was returned. And while Lennon read a book of Marx, the quartet practiced in the park, and we sang dirges in the dark, the day the music died.";
        char scrambled[259];
        scramble_sentence(orig, scrambled);
        printf("Test 2\n");
        printf("Original :%s\n", orig);
        printf("Scrambled:%s\n", scrambled);
    }

    {
        char orig[] = "The whole purpose of places like Starbucks is for people with no decision-making ability whatsoever to make six decisions just to buy one cup of coffee. Short, tall, light, dark, caf, decaf, low-fat, non-fat, etc. So people who don't know what the hell they're doing or who on earth they are can, for only $2.95, get not just a cup of coffee but an absolutely defining sense of self: Tall. Decaf. Cappuccino.";
        char scrambled[409];
        scramble_sentence(orig, scrambled);
        printf("Test 2\n");
        printf("Original :%s\n", orig);
        printf("Scrambled:%s\n", scrambled);
    }
}
