#include <stdio.h>

typedef struct {
    int x;
    int y;
} point;

double get_gradient(point p1, point p2) {
    // Corner case: don't divide by 0
    if (p1.x - p2.x == 0) {
        return 0;
    }

    return (double)(p1.y - p2.y) / (p1.x - p2.x);
}

int main(void) {
    {
        point p1 = {6, 4};
        point p2 = {2, 3};
        printf("Test 1\n");
        printf("Expected:0.25\n");
        printf("Actual  :%.2lf\n", get_gradient(p1, p2));
        printf("\n");
    }

    {
        point p1 = {-5, 4};
        point p2 = {2, 3};
        printf("Test 2\n");
        printf("Expected:-0.14\n");
        printf("Actual  :%.2lf\n", get_gradient(p1, p2));
        printf("\n");
    }

    {
        point p1 = {6, 0};
        point p2 = {2, 0};
        printf("Test 3\n");
        printf("Expected:0.00\n");
        printf("Actual  :%.2lf\n", get_gradient(p1, p2));
        printf("\n");
    }

    {
        point p1 = {0, 1};
        point p2 = {0, 0};
        printf("Test 4\n");
        printf("Expected:0.00\n");
        printf("Actual  :%.2lf\n", get_gradient(p1, p2));
        printf("\n");
    }
}
