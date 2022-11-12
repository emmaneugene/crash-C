#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Use recursion to expand and print braces sequentially

void process(char *to_read, char *to_write, int len) {
    char *ptr = to_write;
    while (*ptr != '\0') {
        ptr++;
    }

    while (*to_read != '\0' && *to_read != '{')  {
        *ptr++ = *to_read++;
    }
    

    if (*to_read == '{') {
        to_read++;
        // find closing brace 
        
        char *closing = to_read;
        int brace_count = 0;
        while (*closing != '}') {
            brace_count++;
            closing++;
        }
        
        char brace_string[brace_count + 1];
        for (int i = 0; i < brace_count; i++) {
            brace_string[i] = to_read[i];
        }
        brace_string[brace_count] = '\0';

        char write_copy[len + 1];
        strcpy(write_copy, to_write);
        
        int write_len = strlen(to_write);

        char *token = strtok(brace_string, ",");

        while (token != NULL) {
            strcpy(write_copy + write_len, token);
            process(closing + 1, write_copy, len);

            token = strtok(NULL, ",");
        } 
        
    } else if (*to_read == '\0') {
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