#include <stdio.h>

int main(void) {
    int count;
    printf("Enter count of ascending sequence:");
    scanf("%d", &count);

    int start_num;
    printf("Enter the starting digit:");
    scanf("%d", &start_num);

    for (int i = 0; i < count; i++) {
        for (int j = start_num; j <= start_num + i; j++) {
            printf("%d", j);
        }
        printf(" ");
    }
    printf ("\n");
}