#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Use recursion to expand and print braces sequentially

char *next_token(char *brace) {
    if (*brace == '\0') {
        return NULL;
    }

    int count = 0;
    char *brace_ptr = brace;
    while (*brace_ptr != ',' && *brace_ptr != '\0') {
        count++;
        brace_ptr++;
    }

    char token[count + 1];
    for (int i = 0; i < count; i++) {
        token[i] = brace[i];
    }
    token[count] = '\0';

    // Overwrite old values of brace()
    while (*brace_ptr != '\0')  {
        *brace = *brace_ptr++;
    }
    *brace = *brace_ptr;

    return token;
}

void process(char *to_read, char *to_write, int len) {
    char *read_ptr = to_read;
    char *write_ptr = to_write;
    while (*write_ptr != '\0') {
        write_ptr++;
    }

    while (*read_ptr != '\0' && *read_ptr != '{')  {
        *write_ptr++ = *read_ptr++;
    }


    if (*read_ptr == '{') {
        read_ptr++;
        // find closing brace

        char *closing_ptr = read_ptr;
        int brace_len = 0;
        while (*closing_ptr != '}') {
            brace_len++;
            closing_ptr++;
        }

        char brace_string[brace_len + 1];
        for (int i = 0; i < brace_len; i++) {
            brace_string[i] = read_ptr[i];
        }
        brace_string[brace_len] = '\0';

        char write_copy[len + 1];
        strcpy(write_copy, to_write);

        int write_len = strlen(to_write);

        char *token = strtok(brace_string, ",");

        while (token != NULL) {
            // printf("token: %s\n", token);
            strcpy(write_copy + write_len, token);
            process(closing_ptr + 1, write_copy, len);

            token = strtok(NULL, ",");
        }

    } else if (*read_ptr == '\0') {
        printf("'%s', ", to_write);
    }
}

void expand_braces(char *to_read) {
    int len = strlen(to_read);
    char to_write[len + 1];
    for (int i = 0; i < len + 1; i++) {
        to_write[i] = '\0';
    }

    process(to_read, to_write, len);
    printf("\n");
}

int main(void) {
    {
        printf("Test 1: \n");
        char *string = "abcde";
        printf("Expected: 'abcde', \n");
        printf("Actual: ");
        expand_braces(string);
        printf("\n");
    }

    {
        printf("Test 1: \n");
        char *string = "a{d,c,b}e";
        printf("Expected: 'ade', 'ace', 'abe'\n");
        printf("Actual: ");
        expand_braces(string);
        printf("\n");
    }

    {
        printf("Test 2: \n");
        char *string = "a{b,c}e{f,g}\n";
        printf("Expected: 'abef', 'abeg', 'acef', 'aceg'\n");
        printf("Actual: ");
        expand_braces(string);
        printf("\n");
    }

    {
        printf("Test 3: \n");
        char *string = "abc{d,e,f}{g,happy}";
        printf("Expected: 'abcdg', 'abcdhappy', 'abceg', 'abcehappy', 'abcfg', 'abcfhappy'\n");
        printf("Actual: ");
        expand_braces(string);
        printf("\n");
    }
}
