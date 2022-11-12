#ifndef __TEST_MODE__
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char *name;
    int quantity;
    double price;
} inv_line_item;

typedef struct {
    char *name;
    int quantity;
} order_line_item;

double process_order(int inv_count, inv_line_item *inventory, int order_count, order_line_item *order) {
    bool found_order = false;

    double price = 0;

    // Iterate over orders
    for (int i = 0; i < order_count; i++) {

        // Find order in inventory
        found_order = false;
        for (int j = 0; j < inv_count; j++) {
            if (strcmp(order[i].name, inventory[j].name) == 0) {
                found_order = true;
                if (order[i].quantity > inventory[j].quantity) {
                    return 0;
                } else {
                    inventory[j].quantity -= order[i].quantity;
                    price += order[i].quantity * inventory[j].price; 
                }
            }
        }

        if (!found_order) {
            return 0;
        }
    }
    return price;
}
#endif

int main(void) {
    int test_id = 0;
    double score = 0;
    int test1_passed = 0;
    int test2_passed = 0;
    int test3_passed = 0;

    {
        double score_worth = 1;
        inv_line_item inventory[] = {{"rum", 2, 10.0}, {"gin", 4, 2.0}};
        order_line_item purchase[] = {{"rum", 2}};
        double total_price_expected = 20;
        double total_price_actual   = process_order(sizeof(inventory)/sizeof(inv_line_item), inventory, sizeof(purchase)/sizeof(order_line_item), purchase);
        int quantity_expected[] = { 0, 4 };

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Expected total price: %.1f\n", total_price_expected);
        printf("Actual total price:   %.1f\n", total_price_actual);
        for (int i = 0; i < sizeof(inventory) / sizeof(*inventory); i++) {
            printf("Expected %s quantity: %d\n", inventory[i].name, quantity_expected[i]);
            printf("Actual %s quantity:   %d\n", inventory[i].name, inventory[i].quantity);
        }

        if (total_price_actual == total_price_actual) {
            int correct = 1;
            for (int i = 0; i < sizeof(inventory) / sizeof(*inventory); i++) {
                if (quantity_expected[i] != inventory[i].quantity) {
                    correct = 0;
                }
            }
            if (correct) {
                printf("Score: %.1f/%.1f\n", score_worth, score_worth);
                score += score_worth;
                test1_passed = 1;
            } else {
                test1_passed = 0;
                printf("Score: 0/%.1f\n", score_worth, score_worth);
            }
        }
        printf("\n");
    }

    {
        double score_worth = 1;
        inv_line_item inventory[] = {{"rum", 2, 10.0}, {"gin", 4, 5.0}};
        order_line_item purchase[] = {{"gin", 2}};
        double total_price_expected = 10;
        double total_price_actual   = process_order(sizeof(inventory)/sizeof(inv_line_item), inventory, sizeof(purchase)/sizeof(order_line_item), purchase);
        int quantity_expected[] = { 2, 2 };

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Expected total price: %.1f\n", total_price_expected);
        printf("Actual total price:   %.1f\n", total_price_actual);
        for (int i = 0; i < sizeof(inventory) / sizeof(*inventory); i++) {
            printf("Expected %s quantity: %d\n", inventory[i].name, quantity_expected[i]);
            printf("Actual %s quantity:   %d\n", inventory[i].name, inventory[i].quantity);
        }

        if (total_price_actual == total_price_actual) {
            int correct = 1;
            for (int i = 0; i < sizeof(inventory) / sizeof(*inventory); i++) {
                if (quantity_expected[i] != inventory[i].quantity) {
                    correct = 0;
                }
            }
            if (correct) {
                printf("Score: %.1f/%.1f\n", score_worth, score_worth);
                score += score_worth;
                test2_passed = 1;
            } else {
                test2_passed = 0;
                printf("Score: 0/%.1f\n", score_worth, score_worth);
            }
        }
        printf("\n");
    }


    {
        double score_worth = 1;
        inv_line_item inventory[] = {{"rum", 2, 10.0}, {"gin", 4, 5.0}};
        order_line_item purchase[] = {{"rum", 1}, {"gin", 1}};
        double total_price_expected = 15;
        double total_price_actual   = process_order(sizeof(inventory)/sizeof(inv_line_item), inventory, sizeof(purchase)/sizeof(order_line_item), purchase);
        int quantity_expected[] = { 1, 3 };

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Expected total price: %.1f\n", total_price_expected);
        printf("Actual total price:   %.1f\n", total_price_actual);
        for (int i = 0; i < sizeof(inventory) / sizeof(*inventory); i++) {
            printf("Expected %s quantity: %d\n", inventory[i].name, quantity_expected[i]);
            printf("Actual %s quantity:   %d\n", inventory[i].name, inventory[i].quantity);
        }

        if (total_price_actual == total_price_actual) {
            int correct = 1;
            for (int i = 0; i < sizeof(inventory) / sizeof(*inventory); i++) {
                if (quantity_expected[i] != inventory[i].quantity) {
                    correct = 0;
                }
            }
            if (correct) {
                printf("Score: %.1f/%.1f\n", score_worth, score_worth);
                score += score_worth;
                test3_passed = 1;
            } else {
                test3_passed = 0;
                printf("Score: 0/%.1f\n", score_worth, score_worth);
            }
        }
        printf("\n");
    }

    if (! (test1_passed && test2_passed && test3_passed)) {
        printf("Test %d is skipped, because one or more of the 1st 3 test cases failed.\n", ++test_id);
    } else {
        double score_worth = 1;
        inv_line_item inventory[] = {{"rum", 2, 10.0}, {"gin", 4, 5.0}};
        order_line_item purchase[] = {{"rum", 10}};
        double total_price_expected = 0;
        double total_price_actual   = process_order(sizeof(inventory)/sizeof(inv_line_item), inventory, sizeof(purchase)/sizeof(order_line_item), purchase);
        int quantity_expected[] = { 2, 4 };

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Expected total price: %.1f\n", total_price_expected);
        printf("Actual total price:   %.1f\n", total_price_actual);
        for (int i = 0; i < sizeof(inventory) / sizeof(*inventory); i++) {
            printf("Expected %s quantity: %d\n", inventory[i].name, quantity_expected[i]);
            printf("Actual %s quantity:   %d\n", inventory[i].name, inventory[i].quantity);
        }

        if (total_price_actual == total_price_actual) {
            int correct = 1;
            for (int i = 0; i < sizeof(inventory) / sizeof(*inventory); i++) {
                if (quantity_expected[i] != inventory[i].quantity) {
                    correct = 0;
                }
            }
            if (correct) {
                printf("Score: %.1f/%.1f\n", score_worth, score_worth);
                score += score_worth;
            } else {
                printf("Score: 0/%.1f\n", score_worth, score_worth);
            }
        }
        printf("\n");
    }

    if (! (test1_passed && test2_passed && test3_passed)) {
        printf("Test %d is skipped, because one or more of the 1st 3 test cases failed.\n", ++test_id);
    } else {
        double score_worth = 1;
        inv_line_item inventory[] = {{"rum", 2, 10.0}, {"gin", 4, 5.0}};
        order_line_item purchase[] = {{"banana", 10}};
        double total_price_expected = 0;
        double total_price_actual   = process_order(sizeof(inventory)/sizeof(inv_line_item), inventory, sizeof(purchase)/sizeof(order_line_item), purchase);
        int quantity_expected[] = { 2, 4 };

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Expected total price: %.1f\n", total_price_expected);
        printf("Actual total price:   %.1f\n", total_price_actual);
        for (int i = 0; i < sizeof(inventory) / sizeof(*inventory); i++) {
            printf("Expected %s quantity: %d\n", inventory[i].name, quantity_expected[i]);
            printf("Actual %s quantity:   %d\n", inventory[i].name, inventory[i].quantity);
        }

        if (total_price_actual == total_price_actual) {
            int correct = 1;
            for (int i = 0; i < sizeof(inventory) / sizeof(*inventory); i++) {
                if (quantity_expected[i] != inventory[i].quantity) {
                    correct = 0;
                }
            }
            if (correct) {
                printf("Score: %.1f/%.1f\n", score_worth, score_worth);
                score += score_worth;
            } else {
                printf("Score: 0/%.1f\n", score_worth, score_worth);
            }
        }
        printf("\n");
    }

    if (! (test1_passed && test2_passed && test3_passed)) {
        printf("Test %d is skipped, because one or more of the 1st 3 test cases failed.\n", ++test_id);
    } else {
        double score_worth = 1;
        inv_line_item inventory[] = {{"rum", 2, 10.0}, {"gin", 4, 5.0}};
        order_line_item purchase[] = {{"rum", 1}, {"gin", 10}};
        double total_price_expected = 0;
        double total_price_actual   = process_order(sizeof(inventory)/sizeof(inv_line_item), inventory, sizeof(purchase)/sizeof(order_line_item), purchase);
        int quantity_expected[] = { 2, 4 };

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Expected total price: %.1f\n", total_price_expected);
        printf("Actual total price:   %.1f\n", total_price_actual);
        for (int i = 0; i < sizeof(inventory) / sizeof(*inventory); i++) {
            printf("Expected %s quantity: %d\n", inventory[i].name, quantity_expected[i]);
            printf("Actual %s quantity:   %d\n", inventory[i].name, inventory[i].quantity);
        }

        if (total_price_actual == total_price_actual) {
            int correct = 1;
            for (int i = 0; i < sizeof(inventory) / sizeof(*inventory); i++) {
                if (quantity_expected[i] != inventory[i].quantity) {
                    correct = 0;
                }
            }
            if (correct) {
                printf("Score: %.1f/%.1f\n", score_worth, score_worth);
                score += score_worth;
            } else {
                printf("Score: 0/%.1f\n", score_worth, score_worth);
            }
        }
        printf("\n");
    }

    printf("score,%s,2,%.1f", __FILE__, score);
}