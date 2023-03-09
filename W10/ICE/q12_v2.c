#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int scramble_and_copy_word(char *word, char *scrambled,int len) {
    srand(time(0));
    int rand_index;
    char temp;
    // Copy over word
    for (int i = 0; i < len; i++) {
        scrambled[i] = word[i];
    }
    // Use the Durstenfeld method to scramble word[1] to word[len - 2]
    for (int i = 1; i < len - 1; i++) {

        // Get random character from remaining list
        do {
            rand_index = rand() % (len - 1 - i) + i;
        } while ((len - 1 - i) > 1 && rand_index == i);

        // Swap the ith character with the random character
        temp = scrambled[i];
        scrambled[i] = scrambled[rand_index];
        scrambled[rand_index] = temp;
    }

    return len;
}

void scramble_sentence(char *original, char *scrambled) {
    // Get next word
    char *next_word = strtok(original, " ");

    while (next_word != NULL) {
        // Scramble next_word and copy to scrambled
        scrambled += scramble_and_copy_word(next_word, scrambled, strlen(next_word));
        *scrambled++ = ' ';

        // Go to next word
        next_word = strtok(NULL, " ");
    }
    *scrambled = '\0';
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

    // {char test[] = "this";
    // scramble(test);
    // printf("%s\n", test);
    // }

    //     {char test[] = "this";
    // scramble(test);
    // printf("%s\n", test);
    // }
    //     {char test[] = "this";
    // scramble(test);
    // printf("%s\n", test);
    // }
}
