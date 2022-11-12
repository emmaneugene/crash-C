#include <stdio.h>
#include <string.h>

void exchange_pairs(char string[]) {
    char temp;
    for (int i = 0; i + 1 < strlen(string); i += 2) {
        temp = string[i];
        string[i] = string[i + 1];
        string[i + 1] = temp;
    }
}

void print_array(char string[]) {
    for (int i = 0; i < strlen(string); i++) {
        printf("%c", string[i]);
    }
    printf("\n");
}

int main(void) {
    {
        char string[] = "abcdef";
        exchange_pairs(string);
        printf("Expected:badcfe\n");
        printf("Actual  :");
        print_array(string);
        printf("\n");
    }

    {
        char string[] = "abcdefg";
        exchange_pairs(string);
        printf("Expected:badcfeg\n");
        printf("Actual  :");
        print_array(string);
        printf("\n");
    }

    {
        char string[] = "a";
        exchange_pairs(string);
        printf("Expected:a\n");
        printf("Actual  :");
        print_array(string);
        printf("\n");
    }
}
