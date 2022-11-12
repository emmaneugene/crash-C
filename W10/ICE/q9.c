#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_good_password(char *password) {
    int len = strlen(password);

    bool lowercase = false;
    bool uppercase = false;
    bool number = false;
    
    while (*password != '\0') {
        if (islower(*password)) {
            lowercase = true;
        } else if (isupper(*password)) {
            uppercase = true;
        } else if (isdigit(*password)) {
            number = true;
        }
        password++;
    }

    return(len >= 6 && len <= 20 && lowercase && uppercase && number);
}

int main(void) {
    {
        char *password = "abc";
        printf("Test 1\n");
        printf("Expected:Pass\n");
        printf("Actual  :%s\n", is_good_password(password) ? "Fail" : "Pass");
        printf("\n");
    }

    {
        char *password = "Abcdefghijklmnopqrst1234";
        printf("Test 2\n");
        printf("Expected:Pass\n");
        printf("Actual  :%s\n", is_good_password(password) ? "Fail" : "Pass");
        printf("\n");
    }

    {
        char *password = "abcdefgh";
        printf("Test 3\n");
        printf("Expected:Pass\n");
        printf("Actual  :%s\n", is_good_password(password) ? "Fail" : "Pass");
        printf("\n");
    }


    {
        char *password = "Abcdefgh";
        printf("Test 4\n");
        printf("Expected:Pass\n");
        printf("Actual  :%s\n", is_good_password(password) ? "Fail" : "Pass");
        printf("\n");
    }

    {
        char *password = "ABCD1234";
        printf("Test 5\n");
        printf("Expected:Pass\n");
        printf("Actual  :%s\n", is_good_password(password) ? "Fail" : "Pass");
        printf("\n");
    }

    {
        char *password = "abcd1234";
        printf("Test 6\n");
        printf("Expected:Pass\n");
        printf("Actual  :%s\n", is_good_password(password) ? "Fail" : "Pass");
        printf("\n");
    }

    {
        char *password = "abcd123A";
        printf("Test 7\n");
        printf("Expected:Pass\n");
        printf("Actual  :%s\n", is_good_password(password) ? "Pass" : "Fail");
        printf("\n");
    }
}
