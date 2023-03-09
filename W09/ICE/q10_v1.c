#include <stdio.h>

int num_length(int count) {
    int len = 0;
    for (; count > 0; count /= 10) {
        len++;
    }
    return len;
}

void run_length_encode(char* input, char* output) {
    char current_char;
    int count;
    while (*input != '\0') {
        // Found a new character - update output and update current_char
        current_char = *input;
        *output++ = *input;

        // Find out how many times it occurs and update count
        count = 0;
        while (*input == current_char) {
            input++;
            count++;
        }

        // Turn count into an array
        int len = num_length(count);
        int count_arr[len];
        for (int i = len - 1; i >= 0; i--) {
            count_arr[i] = count % 10;
            count /= 10;
        }

        // Update count into output
        for (int j = 0; j < len; j++) {
            *output++ = '0' + count_arr[j];
        }
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
