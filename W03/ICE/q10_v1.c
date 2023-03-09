#include <stdio.h>

int main(void) {
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    int prev_num = 0; // declare the first 2 numbers in the sequence
    int next_num = 1;
    int temp_num; // we use this value for the following loop

    if (n >= 1) { //fencepost
        printf("%d ", prev_num);
    }

    for (int i = 1; i < n; i++) {
        printf("%d ", next_num);
        temp_num = prev_num;
        prev_num = next_num; // increment the previous term
        next_num += temp_num; // get the new next term
    }

    printf("\n");
}
