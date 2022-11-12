#include <stdbool.h>
#include <stdio.h>

bool verify(char* card) {
    int count = 0;
    int checksum = 0;
    int next_digit;

    while (*card != '\0') {
        // Get the next digit
        next_digit = (*card) - '0';

        // If the digit is in an odd position (1st, 3rd, 5th, ...), multiply by 2
        if (count % 2 == 0) {
            next_digit *= 2;
            if (next_digit > 9) {
                next_digit -= 9;
            }
        }
        
        // Add to checksum, increment variables
        checksum += next_digit;
        count++;
        card++;
    }
    return (count == 16 && checksum % 10 == 0);
}

int main(void) {
    {
        char *card = "2323200577663554";
        printf("Test 1\n");
        printf("Expected:true\n");
        printf("Actual  :%s\n", verify(card) ? "true" : "false");
        printf("\n");
    }

    {
        char *card = "4041422060806790";
        printf("Test 2\n");
        printf("Expected:true\n");
        printf("Actual  :%s\n", verify(card) ? "true" : "false");
        printf("\n");
    }

    {
        char *card = "5222747000084993";
        printf("Test 3\n");
        printf("Expected:true\n");
        printf("Actual  :%s\n", verify(card) ? "true" : "false");
        printf("\n");
    }

    {
        char *card = "5256392810443201";
        printf("Test 4\n");
        printf("Expected:true\n");
        printf("Actual  :%s\n", verify(card) ? "true" : "false");
        printf("\n");
    }

    {
        char *card = "5256392810443202";
        printf("Test 5\n");
        printf("Expected:false\n");
        printf("Actual  :%s\n", verify(card) ? "true" : "false");
        printf("\n");
    }
    {
        char *card = "2022";
        printf("Test 6\n");
        printf("Expected:false\n");
        printf("Actual  :%s\n", verify(card) ? "true" : "false");
        printf("\n");
    }
}