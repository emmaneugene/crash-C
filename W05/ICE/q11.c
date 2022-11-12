#include <stdio.h>
#include <stdbool.h>

bool are_all_prices_higher_than(int numbers[], int n, int min){
    for (int i = 0; i < n; i++) {
        if (numbers[i] <= min) {
            return false;
        }
    }
    
    return true;
}

int main(void) {
    {
        printf("Test 1\n");
        int values[5] = {1, 2, 9, 10, 12};
        int result = are_all_prices_higher_than(values, 5, 5);
        printf("Expected:Fail\n"); 
        printf("Actual  :%s\n\n",  result ? "Pass" : "Fail");
    }

    {
        printf("Test 2\n");
        int values[4] = {5, 7, 10, 12};
        int result = are_all_prices_higher_than(values, 4, 5);
        printf("Expected:Fail\n");
        printf("Actual  :%s\n\n",  result ? "Pass" : "Fail");
    }

    {
        printf("Test 3\n");
        int values[4] = {9, 7, 10, 1};
        int result = are_all_prices_higher_than(values, 4, 5);
        printf("Expected:Fail\n");
        printf("Actual  :%s\n\n",  result ? "Pass" : "Fail");
    }

    {
        printf("Test 4\n");
        int values[3] = {9, 7, 10};
        int result = are_all_prices_higher_than(values, 3, 5);
        printf("Expected:Pass\n");
        printf("Actual  :%s\n\n",  result ? "Pass" : "Fail");
    }

    {
        printf("Test 5\n");
        int values[] = {};
        int result = are_all_prices_higher_than(values, 0, 5);
        printf("Expected:Pass\n");
        printf("Actual  :%s\n\n",  result ? "Pass" : "Fail");
    }
}