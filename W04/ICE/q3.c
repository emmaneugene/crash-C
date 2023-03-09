#include <stdio.h>

int main(void){
    int n1;
    printf("Enter n1>");
    scanf("%d", &n1);

    int n2;
    printf("Enter n2>");
    scanf("%d", &n2);

    while ((n1 + n2) % 3 != 0) {
        printf("Invalid!\n\n");

        printf("Enter n1>");
        scanf("%d", &n1);

        printf("Enter n2>");
        scanf("%d", &n2);
    }

    int max = n1 > n2 ? n1 : n2;
    int min = n1 < n2 ? n1 : n2;

    for (; min <= max; min++) {
        printf("%d ", min);
    }
    printf("\n");
}
