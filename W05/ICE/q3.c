#include <stdio.h>

void print_even_numbers(int n){
    if (n >= 2) {
        printf("{2}");
    }

    for (int i = 4; i <= n; i += 2) {
        printf(" {%d}", i);
    }
}

int main(void) {
    printf("Test 1\n");
    printf("Expected:[{2}]\n");
    printf("Actual  :[");
    print_even_numbers(2);
    printf("]\n\n");

    printf("Test 2\n");
    printf("Expected:[]\n");
    printf("Actual  :[");
    print_even_numbers(1);
    printf("]\n\n");

    printf("Test 3\n");
    printf("Expected:[]\n");
    printf("Actual  :[");
    print_even_numbers(-3);
    printf("]\n\n");

    printf("Test 4\n");
    printf("Expected:[{2} {4} {6} {8} {10} {12}]\n");
    printf("Actual  :[");
    print_even_numbers(13);
    printf("]\n\n");

    printf("Test 4\n");
    printf("Expected:[{2} {4} {6} {8} {10} {12} {14}]\n");
    printf("Actual  :[");
    print_even_numbers(14);
    printf("]\n\n");

}
