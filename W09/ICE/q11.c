#include <stdio.h>
#include <ctype.h>
#include <math.h>

void encode(char* plaintext, char* ciphertext, int key) {
    // Iterate to end of plaintext
    for (int i = 0; *(plaintext + i) != '\0'; i++) {
        if (isalpha(*(plaintext + i))) {

            // Encode before copying over
            if (isupper(*(plaintext + i))) {
                // Convert uppercase
                *(ciphertext + i) = (*(plaintext + i) - 'A' + key) % 26 + 'A';
            } else {
                // Convert lowercase
                *(ciphertext + i) = (*(plaintext + i) - 'a' + key) % 26 + 'a';
            }
        } else {
            // Copy without changing
            *(ciphertext + i) = *(plaintext + i);
        }
    }
}

void decode(char* plaintext, char* ciphertext, int key) {
    // Iterate to end of ciphertext
    for (int i = 0; *(ciphertext + i) != '\0'; i++) {
        if (isalpha(*(ciphertext + i))) {

            // Encode before copying over
            if (isupper(*(ciphertext + i))) {
                // Convert uppercase
                *(plaintext + i) = (*(ciphertext + i) - 'A' - key % 26) % 26 + 'A';

                // If *(ciphertext + i) - 'A' - key % 26 is a negative value, add 26
                if (*(ciphertext + i) - 'A' < key % 26) {
                    *(plaintext + i) += 26;
                }
            } else {
                // Convert lowercase
                *(plaintext + i) = (*(ciphertext + i) - 'a' - key % 26) % 26 + 'a';

                // If *(ciphertext + i) - 'a' - key % 26 is a negative value, add 26
                if (*(ciphertext + i) - 'a' < key % 26) {
                    *(plaintext + i) += 26;
                }
            }
        } else {
            // Copy without changing
            *(plaintext + i) = *(ciphertext + i);
        }
    }
}

int main(void) {
    {
        char *plaintext = "abc";
        char ciphertext[4] = {0};
        encode(plaintext, ciphertext, 1);
        printf("Test 1\n");
        printf("Expected:bcd\n");
        printf("Actual  :%s\n", ciphertext);
        printf("\n");
    }

    {
        char *plaintext = "abc";
        char ciphertext[4] = {0};
        encode(plaintext, ciphertext, 27);
        printf("Test 2\n");
        printf("Expected:bcd\n");
        printf("Actual  :%s\n", ciphertext);
        printf("\n");
    }

    {
        char *plaintext = "apples and oranges. Which do you prefer?";
        char ciphertext[45] = {0};
        encode(plaintext, ciphertext, 13);
        printf("Test 3\n");
        printf("Expected:nccyrf naq benatrf. Juvpu qb lbh cersre?\n");
        printf("Actual  :%s\n", ciphertext);
        printf("\n");
    }

    {
        char *plaintext = "###";
        char ciphertext[4] = {0};
        encode(plaintext, ciphertext, 13);
        printf("Test 4\n");
        printf("Expected:###\n");
        printf("Actual  :%s\n", ciphertext);
        printf("\n");
    }

    // ------
    {
        char *ciphertext = "bcd";
        char plaintext[4] = {0};
        decode(plaintext, ciphertext, 1);
        printf("Test 5\n");
        printf("Expected:abc\n");
        printf("Actual  :%s\n", plaintext);
        printf("\n");
    }

    {
        char *ciphertext = "bcd";
        char plaintext[4] = {0};
        decode(plaintext, ciphertext, 27);
        printf("Test 6\n");
        printf("Expected:abc\n");
        printf("Actual  :%s\n", plaintext);
        printf("\n");
    }

    {
        char *ciphertext = "P gur yvtug ng gur raq bs gur ghaary";
        char plaintext[40] = {0};
        decode(plaintext, ciphertext, 13);
        printf("Test 7\n");
        printf("Expected:C the light at the end of the tunnel\n");
        printf("Actual  :%s\n", plaintext);
        printf("\n");
    }

    {
        char *ciphertext = "abc 123";
        char plaintext[40] = {0};
        decode(plaintext, ciphertext, 26);
        printf("Test 7\n");
        printf("Expected:abc 123\n");
        printf("Actual  :%s\n", plaintext);
        printf("\n");
    }
}