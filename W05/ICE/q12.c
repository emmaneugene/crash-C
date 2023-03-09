#include <stdio.h>
#include <stdbool.h>

void print_calendar(int num_days, int first_sun) {
    printf("Su Mo Tu We Th Fr Sa\n");

    // Print whitespaces if necessary
    if (first_sun > 1) {
        printf("  ");
        for (int i = 0; i < (7 - first_sun); i++) {
            printf("   ");
        }
    }

    // Print out the rest of the calendar
    for (int j = 1; j <= num_days; j++) {
        // If the number is single digit, print a space
        if (j < 10) {
            printf(" ");
        }
        // If the number is not in the left corner, print a space
        if((j - first_sun) % 7 != 0) {
            printf(" ");
        }
        printf("%d", j);
        // Condition to print a newline
        if ((j - first_sun + 1) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int day_of_week(int day, int mth, int yr){
    // Get year code
    int year_code = (yr % 100 + (yr % 100) / 4) % 7;

    // Get month code
    int month_code;
    int month_code_array[12] = {0, 3, 3, 6 , 1, 4, 6, 2, 5, 0, 3, 5};
    month_code = month_code_array[mth - 1];

    // Get century code
    int century_code;
    int century_num = yr / 100;
    if (yr < 1752 || (yr == 1752 && mth <= 9 && day <= 2)) {
        // For Julian Calendar
        century_code = (18 - century_num) % 7;
    } else {
        // For Gregorian Calendar
        if (century_num % 4 == 1) {
            century_code = 4;
        } else if (century_num % 4 == 2) {
            century_code = 2;
        } else if (century_num % 4 == 3) {
            century_code = 0;
        } else {
            century_code = 6;
        }
    }

    // Get leap year code, only for Jan/Feb of leap years
    int leap_year_code = 0;

    if (mth < 3) {
        if (yr < 1752 || (yr == 1752 && mth <= 9 && day <= 2)) {
            // For Julian Calendar
            if (yr % 4 == 0) {
                leap_year_code = 1;
            }
        } else {
            // For Gregorian Calendar
            if (yr % 400 == 0) {
                leap_year_code = 1;
            } else if (yr % 4 == 0 && yr % 100 != 0) {
                leap_year_code = 1;
            }
        }
    }

    // Calculate
    return (year_code + month_code + century_code + day - leap_year_code) % 7;
}

bool is_leap_year(int yr){
    if (yr <= 1752) {
        return yr % 4 == 0;
    } else {
        return (yr % 400 == 0 || (yr % 4 == 0 && yr % 100 != 0));
    }
}

void print_calendar_for_mth(int mth, int yr){
    int first_sun;
    if (day_of_week(1, mth, yr) == 0) {
        first_sun = 1;
    } else {
        first_sun = 8 - day_of_week(1, mth, yr);
    }

    int num_days;
    switch (mth) {
        case 2:
            num_days = is_leap_year(yr) ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            num_days = 30;
            break;
        default:
            num_days = 31;
    }

    print_calendar(num_days, first_sun);
}

int main(void) {
    print_calendar(31, 5);
    printf("\n");
    print_calendar(29, 3);
    printf("\n");
    print_calendar(28, 7);

    printf("------------------------------------\n");

    printf("Einstein was born on: %d\n\n", day_of_week(14, 3, 1897));
    printf("I was born on: %d\n\n", day_of_week(14, 11, 1997));
    printf("The moon landing was on: %d\n\n", day_of_week(20, 7, 1969));
    printf("1/1/2000 was: %d\n\n", day_of_week(1, 1, 2000));
    printf("The battle of Hastings was on: %d\n\n", day_of_week(14, 10, 1066));

    printf("------------------------------------\n");

    printf("Jan 2000\n");
    print_calendar_for_mth(1, 2000);
    printf("\n");
    printf("Sep 2019\n");
    print_calendar_for_mth(9, 2019);
    printf("\n");
    printf("Feb 2020\n");
    print_calendar_for_mth(2, 2020);
}
