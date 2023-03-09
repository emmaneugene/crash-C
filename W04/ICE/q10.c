#include <stdio.h>

int main(void){
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("On the ");
        switch (i) {
            case 12:
                printf("twelfth");
                break;
            case 11:
                printf("eleventh");
                break;
            case 10:
                printf("tenth");
                break;
            case 9:
                printf("ninth");
                break;
            case 8:
                printf("eighth");
                break;
            case 7:
                printf("seventh");
                break;
            case 6:
                printf("sixth");
                break;
            case 5:
                printf("fifth");
                break;
            case 4:
                printf("fourth");
                break;
            case 3:
                printf("third");
                break;
            case 2:
                printf("second");
                break;
            case 1:
                printf("first");
        }
        printf(" day of Christmas my true love sent to me\n");

        switch (i) {
            case 12:
                printf("12 drummers drumming\n");
            case 11:
                printf("11 pipers piping\n");
            case 10:
                printf("10 lords a-leaping\n");
            case 9:
                printf("9 ladies dancing\n");
            case 8:
                printf("8 maids a-milking\n");
            case 7:
                printf("7 swans a-swimming\n");
            case 6:
                printf("6 geese a-laying\n");
            case 5:
                printf("5 gold rings\n");
            case 4:
                printf("4 calling birds\n");
            case 3:
                printf("3 french hens\n");
            case 2:
                printf("2 turtle doves\nand ");
            case 1:
                printf("a partridge in a pear tree\n");
        }
    }
}
