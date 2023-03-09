#include <stdio.h>

int main(void){
    int n_males, n_females;
    printf("Enter num males: ");
    scanf("%d", &n_males);
    printf("Enter num females: ");
    scanf("%d", &n_females);
    printf("Percentage(Females)= %.1lf%%\n", 100 * (double)n_females / (n_males + n_females));
}
