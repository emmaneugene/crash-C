#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int precedence(char op) {
    switch (op) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        default:
            return 1;
    }
}

bool is_operator(char op) {
    switch (op) {
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
            break;
        default:
            return false;
    }
    return true;
}

char *convert_postfix(char *exp) {
    int len = strlen(exp);

    // output string
    char *output = calloc(len, sizeof(char));

    // operator stack
    char stk[len];

    int op_idx = 0;
    int stk_idx = 0;

    while (*exp) {
        if (isdigit(*exp)) {
            output[op_idx++] = *exp;
        } else if (*exp == '(') {
            stk[stk_idx++] = *exp;
        } else if (*exp == ')') {
            while (stk[stk_idx - 1] != '(' && stk_idx != 0) {
                output[op_idx++] = stk[stk_idx - 1];
                stk_idx--;
            }
        } else if (is_operator(*exp)) {
            while (precedence(stk[stk_idx - 1]) >= precedence(*exp) && stk_idx != 0) {
                output[op_idx++] = stk[stk_idx - 1];
                stk_idx--;
            }
            stk[stk_idx++] = *exp;
        }

        exp++;
    }

    while (stk_idx != 0) {
        if (is_operator(stk[stk_idx - 1])) {
            output[op_idx++] = stk[stk_idx - 1];
        }
        stk_idx--;
    }

    printf("op_idx: %d\n", op_idx);
    return output;
}

// int calculate(char *exp) {
//     int len = strlen(exp);
//     char []
// }

int main(void) {
    char exp[20] = {0};
    printf("Enter exp: ");
    scanf("%20[^\n]", exp);

    char *posfix_exp = convert_postfix(exp);

    printf("Converted postfix exp: %s\n", posfix_exp);

    // printf("%d\n", calculate(posfix_exp));
}
