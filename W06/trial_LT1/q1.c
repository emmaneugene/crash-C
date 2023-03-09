/**
 *
 * Name: Emmanuel Oh Eu-Gene
 * Email: emmanueloh.2019@sis.smu.edu.sg
 *
 */
#include <stdio.h>

int calculate_ticket_price(int age) {
    int price;
    if (age >= 60) {
        price = 38;
    } else if (age >= 13) {
        price = 76;
    } else if (age >= 4) {
        price = 56;
    } else {
        price = 0;
    }
    return price;
}

int main(void) {
    printf("Test 1\n");
    printf("Expected:76\n");
    printf("Actual  :%d\n", calculate_ticket_price(13));
    printf("\n");

    printf("Test 2\n");
    printf("Expected:56\n");
    printf("Actual  :%d\n", calculate_ticket_price(12));
    printf("\n");

    printf("Test 3\n");
    printf("Expected:38\n");
    printf("Actual  :%d\n", calculate_ticket_price(99));
    printf("\n");

    printf("Test 3\n");
    printf("Expected:0\n");
    printf("Actual  :%d\n", calculate_ticket_price(3));
    printf("\n");
}
