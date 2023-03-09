#include <stdio.h>

int main(void) {
    int count;
    printf("Enter count of ascending sequence:");
    scanf("%d", &count);

    int start_num;
    printf("Enter the starting digit:");
    scanf("%d", &start_num);

    int num = 0;
    for (int i = start_num; i < start_num + count; i++) {
        num *= 10;
        num += i;
        printf("%d ", num);
    }
    printf ("\n");
}
