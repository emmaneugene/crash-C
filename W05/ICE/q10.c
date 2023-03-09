#include <stdio.h>

int get_largest(int array[], int n){
    int largest_in_array = 0;

    for (int i = 0; i < n; i++) {
        if(array[i] > largest_in_array) {
            largest_in_array = array[i];
        }
    }
    return largest_in_array;
}

int main(void) {
    {
        printf("Test 1\n");
        int array[5] = {5, 7, 9, 11, 2};
        int result = get_largest(array, 5);
        printf("Expected:11\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 2\n");
        int array[5] = {12, 7, 9, 11, 2};
        int result = get_largest(array, 5);
        printf("Expected:12\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 3\n");
        int array[6] = {12, 7, 9, 11, 1, 20};
        int result = get_largest(array, 6);
        printf("Expected:20\n");
        printf("Actual  :%d\n\n", result);
    }


    {
        printf("Test 4\n");
        int array[1] = {12};
        int result = get_largest(array, 1);
        printf("Expected:12\n");
        printf("Actual  :%d\n\n", result);
    }

}
