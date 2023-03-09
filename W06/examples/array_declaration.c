#include <stdio.h>

int main(void){
    int array_one[3] = {1, 2, 3};
    int array_two[4] = {4, 5, 6, 7};

    for (int i = 0; i < 4; i++) {
        array_one[i] = array_two[i];
    }

    for (int j = 0; j < 4; j++) {
        printf("%d ", array_one[j]);
    }
    printf("\n");
}
