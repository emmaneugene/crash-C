/*
   Name : Emmanuel Oh Eu-Gene
   Email: emmanueloh.2019@sis.smu.edu.sg
 */

#include <stdbool.h>
#include <stdio.h>

void print_snake(char start, char end, int len, int width) {
    // Declare an array of characters
    int charset_len;
    if (end > start) {
        charset_len = end - start + 1;
    } else {
        charset_len = (26 - start + 1) + end;
    }

    int characters[charset_len];
    for (int i = 0; i < charset_len; i++) {
        characters[i] = ((start + i) - 65) % 26 + 65;
    }

    // How many "blocks" of the snake need to be printed
    int num_blocks = len / (width + 1);
    // Characters leftover
    int leftover = len % (width + 1); 
    // Print the leftover
    len--;
    if (leftover > 0) {
        if (num_blocks % 2 == 0) {
            for (int i = 0; i < width - leftover; i++) {
                printf(" ");
            }
            for (int i = 0; i < leftover; i++) {
                printf("%c", characters[len-- % charset_len]);
            }
        } else {
            len -= leftover;
            for (int i = 1; i <= leftover; i++) {
                printf("%c", characters[(len + i) % charset_len]);
            }
            
        }
        printf("\n");
    }

    for (;num_blocks > 0; num_blocks--) {
        if (num_blocks % 2 == 0) {
            // Print rightward block
            // First row
            for (int i = 0; i < width - 1; i++) {
                printf(" ");
            }
            printf("%c\n", characters[len-- % charset_len]);
            // Next row
            len -= width;
            for (int i = 1; i <= width; i++) {
                printf("%c", characters[(len + i) % charset_len]);
            }
            printf("\n");
        } else {
            // Print leftward block
            // First row
            printf("%c", characters[len-- % charset_len]);
            printf("\n");
            // Next row
            for (int i = 0; i < width; i++) {
                printf("%c", characters[len-- % charset_len]);
            }
            printf("\n");
        }
    }
}

int main(void) {
    {
        printf("=== Test 1 ===\n");
        printf("Expected:\n");
        printf("  LK\n");
        printf("   J\n");
        printf("FGHI\n");
        printf("E   \n");
        printf("DCBA\n");
        printf("\n");
        printf("Actual:\n");
        print_snake('A', 'L', 12, 4);
        printf("--------------------------------\n");
    }

    {
        printf("=== Test 2 ===\n");
        printf("Expected:\n");
        printf("C  \n");
        printf("BAC\n");
        printf("  B\n");
        printf("BCA\n");
        printf("A  \n");
        printf("CBA\n");
        printf("\n");
        printf("Actual:\n");
        print_snake('A', 'C', 12, 3);
        printf("--------------------------------\n");
    }

    {
        printf("=== Test 3 ===\n");
        printf("Expected:\n");
        printf("    B\n");
        printf("ABYZA\n");
        printf("Z\n");
        printf("YBAZY\n");
        printf("\n");
        printf("Actual:\n");
        print_snake('Y', 'B', 12, 5);
        printf("--------------------------------\n");
    }

    {
        printf("=== Test 4 ===\n");
        printf("Expected:\n");
        printf("   L\n");
        printf("   K\n");
        printf("GHIJ\n");
        printf("F\n");
        printf("EDCB\n");
        printf("\n");
        printf("Actual:\n");
        print_snake('B', 'M', 11, 4);
        printf("--------------------------------\n");
    }

    {
        printf("=== Test 5 ===\n");
        printf("Expected:\n");
        printf(" I\n");
        printf("GH\n");
        printf("F\n");
        printf("ED\n");
        printf(" C\n");
        printf("AB\n");
        printf("Z\n");
        printf("YX\n");
        printf("\n");
        printf("Actual:\n");
        print_snake('X', 'W', 12, 2);
        printf("--------------------------------\n");
    }
}