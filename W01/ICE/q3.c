#include <stdio.h>

int main(void){
    printf("N\tN^2\tN^3\n");
    for(int i = 0; i < 11; i++)
    {
        printf("%d\t%d\t%d\n", i, i * i, i * i * i);
    }
}
