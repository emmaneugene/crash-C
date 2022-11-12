#include <stdio.h>

int main(void){
    int mAh, V;
    printf("Enter capacity(mAh): ");
    scanf("%d", &mAh);
    printf("Enter voltage(V): ");
    scanf("%d", &V);
    printf("rated power: %d Wh\n", mAh / 1000 * V);
}

