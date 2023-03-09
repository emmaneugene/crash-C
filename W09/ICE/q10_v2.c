#include <stdio.h>

void run_length_encode(char* input, char* output) {
    char current_char;
    int count;
    while (*input != '\0') {
        // Found a new character - update output and update current_char
        current_char = *input;
        *output++ = current_char;

        // Find out how many times it occurs and update count
        count = 0;
        while (*input == current_char) {
            input++;
            count++;
        }

        // Write the count into output
        output += sprintf(output, "%d", count);
    }
}

int main(void) {
    {
        printf("Test 1\n");
        char *input = "aaaaaaaaaabbbaxxxxyyyzyx";
        char output[25] = {0};
        run_length_encode(input, output);
        printf("Expected:a10b3a1x4y3z1y1x1\n");
        printf("Actual  :%s\n", output);
    }

    {
        printf("Test 2\n");
        char *input = "";
        char output[25] = {0};
        run_length_encode(input, output);
        printf("Expected:><\n");
        printf("Actual  :>%s<\n", output);
    }
}
