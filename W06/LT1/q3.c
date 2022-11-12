/*
   Name : Emmanuel Oh Eu-Gene
   Email: emmanueloh.2019@sis.smu.edu.sg
 */

#include <stdio.h>

void print_season(int day, int month) {
    // Corner cases for invalid dates
    if (month > 12 || month < 1 || day > 31 || day < 1) {
        printf("invalid\n");
        return;
    } else if (month == 2 && day > 28) {
        printf("invalid\n");
        return;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            printf("invalid\n");
            return;
        }
    }

    // Check through the seasons

    if ((month > 3 || (month == 3 && day >= 20)) && (month < 6 || (month == 6 && day <= 20))) {
        // Conditions for Spring
        printf("spring\n");
        return;
    } else if ((month > 6 || (month == 6 && day >= 21)) && (month < 9 || (month == 9 && day <= 22))) {
        // Conditions for Summer
        printf("summer\n");
        return;
    } else if ((month > 9 || (month == 9 && day >= 23)) && (month < 12 || (month == 12 && day <= 21))) {
        // Conditions for Fall
        printf("fall\n");
        return;
    } else {
        printf("winter\n");
        return;
    }
}

int main(void) {
    {
        printf("Test 1\n");
        printf("Expected:spring\n");
        printf("Actual  :");
        print_season(5, 5);
        printf("\n");
    }

    {
        printf("Test 2\n");
        printf("Expected:summer\n");
        printf("Actual  :");
        print_season(5, 7);
        printf("\n");
    }

    {
        printf("Test 3\n");
        printf("Expected:fall\n");
        printf("Actual  :");
        print_season(5, 11);
        printf("\n");
    }

    {
        printf("Test 4\n");
        printf("Expected:winter\n");
        printf("Actual  :");
        print_season(5, 1);
        printf("\n");
    }

    {
        printf("Test 5\n");
        printf("Expected:invalid\n");
        printf("Actual  :");
        print_season(1, 13);
        printf("\n");
    }

    {
        printf("Test 6\n");
        printf("Expected:invalid\n");
        printf("Actual  :");
        print_season(31, 4);
        printf("\n");
    }

    {
        printf("Test 7\n");
        printf("Expected:invalid\n");
        printf("Actual  :");
        print_season(-1, 4);
        printf("\n");
    }
}
