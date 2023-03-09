#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    }

    return false;
}

int days_for_month_in_year(int month, int year) {
    switch (month) {
        case 2:
            return is_leap_year(year) ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        default:
            return 31;
    }
}

int days_elapsed_since_year(int day, int month, int year, int base_year) {
    int days = 0;
    for (int i = base_year; i < year; i++) {
        days += is_leap_year(i) ? 366 : 365;
    }

    for (int i = 1; i < month; i++) {
        days += days_for_month_in_year(i, year);
    }

    return days + day;
}

int get_num_days_between(int d1, int m1, int y1, int d2, int m2, int y2) {
    int smallest_year = y1 < y2 ? y1 : y2;

    int date1 = days_elapsed_since_year(d1, m1, y1, smallest_year);

    int date2 = days_elapsed_since_year(d2, m2, y2, smallest_year);

    return date1 - date2;
}



// ------------------------TESTS------------------------

int main(void) {
    printf("Expected: 31\n");
    printf("Actual  : ");
    printf("%d\n", get_num_days_between(1, 2, 1970, 1, 1, 1970));

    printf("%d\n", get_num_days_between(16, 12, 2019, 16, 12, 2020));
}
