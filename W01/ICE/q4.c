#include <stdio.h>

int main(void){
    int time_in_seconds;
    printf("Enter time in seconds: ");
    scanf("%d", &time_in_seconds);
    printf("%d seconds is %.2d:%.2d:%.2d (HH:MM:SS)\n", time_in_seconds, time_in_seconds / 3600, time_in_seconds % 3600 /  60, time_in_seconds % 3600 % 60 );
    // .2 will format an integer for you as well
}