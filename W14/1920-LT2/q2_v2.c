/**
 * Name : Emmanuel Oh Eu-Gene
 * Email: emmanueloh.2019@sis.smu.edu.sg
 */

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
    bool valid_order = false;

    // First pass: check all orders are valid
    for (int i = 0; i < order_count; i++) {
        valid_order = false;
        for (int j = 0; j < inv_count; j++) {
            if (strcmp(order[i].name, inventory[j].name) == 0 && order[i].quantity <= inventory[i].quantity) {
                valid_order = true;                
            }
        }

        if (!valid_order) {
            return 0;
        }
    }

    double price = 0;    

    // Second pass: process order
    for (int i = 0; i < order_count; i++) {
        for (int j = 0; j < inv_count; j++) {
            if (strcmp(order[i].name, inventory[j].name) == 0) {
                inventory[j].quantity -= order[i].quantity;
                price += order[i].quantity * inventory[j].price;
            }
        }
    }

    return price;
}

int main(void) {
    int test_id = 0;

    {
        inv_line_item inventory[] = {{"apple", 3, 0.5}, {"orange", 4, 0.6}};
        order_line_item purchase[] = {{"apple", 3}};
        double result = process_order(sizeof(inventory)/sizeof(inv_line_item), inventory, sizeof(purchase)/sizeof(order_line_item), purchase);
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Expected return value:1.50\n");
        printf("Actual return value  :%.2lf\n", result);
        printf("Expected apple qty   :0\n");
        printf("Expected apple qty   :%d\n", inventory[0].quantity);
        printf("\n");
    }

    {
        inv_line_item inventory[] = {{"apple", 3, 0.5}, {"orange", 4, 0.6}, {"pear", 5, 0.7}};
        order_line_item purchase[] = {{"apple", 3}, {"banana", 3}};
        double result = process_order(sizeof(inventory)/sizeof(inv_line_item), inventory, sizeof(purchase)/sizeof(order_line_item), purchase);
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Expected return value:0.00\n");
        printf("Actual return value  :%.2lf\n", result);
        printf("Expected apple qty   :3\n");
        printf("Expected apple qty   :%d\n", inventory[0].quantity);
        printf("\n");
    }

    {
        inv_line_item inventory[] = {{"apple", 3, 0.5}, {"orange", 4, 0.6}, {"pear", 5, 0.7}};
        order_line_item purchase[] = {{"apple", 5}, {"orange", 3}};
        double result = process_order(sizeof(inventory)/sizeof(inv_line_item), inventory, sizeof(purchase)/sizeof(order_line_item), purchase);
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Expected return value:0.00\n");
        printf("Actual return value  :%.2lf\n", result);
        printf("Expected apple qty   :3\n");
        printf("Expected apple qty   :%d\n", inventory[0].quantity);
        printf("Expected orange qty  :4\n");
        printf("Expected orange qty  :%d\n", inventory[1].quantity);
        printf("\n");
    }

    {
        inv_line_item inventory[] = {{"apple", 3, 0.5}, {"orange", 4, 0.6}, {"pear", 5, 0.7}};
        order_line_item purchase[] = {{"apple", 3}, {"orange", 2}};
        double result = process_order(sizeof(inventory)/sizeof(inv_line_item), inventory, sizeof(purchase)/sizeof(order_line_item), purchase);
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Expected return value:2.70\n");
        printf("Actual return value  :%.2lf\n", result);
        printf("Expected apple qty   :0\n");
        printf("Expected apple qty   :%d\n", inventory[0].quantity);
        printf("Expected orange qty  :2\n");
        printf("Expected orange qty  :%d\n", inventory[1].quantity);
        printf("\n");
    }
}