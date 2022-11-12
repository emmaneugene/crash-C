/*
   Name : Emmanuel Oh Eu-Gene
   Email: emmanueloh.2019@sis.smu.edu.sg
 */

#include <stdio.h>
#include <math.h>

int rearrange_digits(int num, int pivot) {
    if (num < 0) {
        return -1 * rearrange_digits(-num, pivot);
    }

    int greater = 0;
    int greater_multiplier = 1;
    int equal = 0;
    int equal_multiplier = 1;
    int lesser = 0;
    int lesser_multiplier = 1;
    int temp = 0;
    

    while (num > 0) {
        temp =  num % 10;
        if (temp > pivot) {
            greater += temp * greater_multiplier;
            greater_multiplier *= 10;
        } else if (temp == pivot) {
            equal += temp * equal_multiplier;
            equal_multiplier *= 10;
        } else {
            lesser += temp * lesser_multiplier;
            lesser_multiplier *= 10;
        }
        num /= 10;
    }

    greater *= equal_multiplier * lesser_multiplier;
    equal *= lesser_multiplier;
    return greater + equal + lesser;
}


int main(void) {
    {
        printf("Test 1\n");
        int result = rearrange_digits(415, 3);
        printf("Expected:451\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        int result = rearrange_digits(123454321, 3);
        printf("Expected:454331221\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        int result = rearrange_digits(61728394, 5);
        printf("Expected:67891234\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 4\n");
        int result = rearrange_digits(61728394, 0);
        printf("Expected:61728394\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 5\n");
        int result = rearrange_digits(6900, 9);
        printf("Expected:9600\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 6\n");
        int result = rearrange_digits(-1245, 3);
        printf("Expected:-4512\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}