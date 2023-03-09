#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
bool is_opening(char p) {
    return p == '(' || p == '{' || p == '[';
}

bool is_closing(char p) {
    return p == ')' || p == '}' || p == ']';
}

bool matching(char opening, char closing) {
    if (opening == '(' && closing == ')') {
        return true;
    }
    if (opening == '{' && closing == '}') {
        return true;
    }
    if (opening == '[' && closing == ']') {
        return true;
    }
    return false;
}

bool is_balanced(char *input) {
    // Create a stack to store open parentheses
    char stack[strlen(input)];

    int idx = 0;
    while (*input) {
        if (is_opening(*input)) {
            stack[idx++] = *input++;
        } else if (is_closing(*input)) {
            if (idx > 0 && matching(stack[idx - 1], *input)) {
                idx--;
                input++;
            } else {
                return false;
            }
        } else {
            input++;
        }
    }

    // Make sure the stack is empty, i.e. idx == 0
    return idx == 0;
}

int main(void) {
    int count = 1;
    {
        char *input = "{[()]}";
        printf("Test %d:\n", count++);
        printf("Expected:true\n");
        printf("Actual  :%s\n", is_balanced(input) ? "true" : "false");
        printf("\n");
    }

    {
        char *input = "{[(])}";
        printf("Test %d:\n", count++);
        printf("Expected:false\n");
        printf("Actual  :%s\n", is_balanced(input) ? "true" : "false");
        printf("\n");
    }

    {
        char *input = "{}[](((((())))))";
        printf("Test %d:\n", count++);
        printf("Expected:true\n");
        printf("Actual  :%s\n", is_balanced(input) ? "true" : "false");
        printf("\n");
    }

    {
        char *input = "{{}[]()}{[][]}";
        printf("Test %d:\n", count++);
        printf("Expected:true\n");
        printf("Actual  :%s\n", is_balanced(input) ? "true" : "false");
        printf("\n");
    }

    {
        char *input = "{{}[[{}]]()}{}[]";
        printf("Test %d:\n", count++);
        printf("Expected:true\n");
        printf("Actual  :%s\n", is_balanced(input) ? "true" : "false");
        printf("\n");
    }

    {
        char *input = "";
        printf("Test %d:\n", count++);
        printf("Expected:true\n");
        printf("Actual  :%s\n", is_balanced(input) ? "true" : "false");
        printf("\n");
    }

    {
        char *input = "{}{}{}}";
        printf("Test %d:\n", count++);
        printf("Expected:false\n");
        printf("Actual  :%s\n", is_balanced(input) ? "true" : "false");
        printf("\n");
    }

    {
        char *input = "{{{{{}}}}} {}{}}";
        printf("Test %d:\n", count++);
        printf("Expected:false\n");
        printf("Actual  :%s\n", is_balanced(input) ? "true" : "false");
        printf("\n");
    }

    {
        char *input = "{{}{}{}";
        printf("Test %d:\n", count++);
        printf("Expected:false\n");
        printf("Actual  :%s\n", is_balanced(input) ? "true" : "false");
        printf("\n");
    }
}
