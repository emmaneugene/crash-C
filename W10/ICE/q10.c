#include <stdio.h>
#include <string.h>

void py_slice(char *orig, char *dest, int start, int end, int step) {
    // Corner cases
    if (step == 0 || (step > 0 && start > end) || (step < 0 && start < end)) {
        *dest = '\0';
        return;
    }
    
    int len = strlen(orig);

    // Make sure start <= len - 1(inclusive)
    if (start > len - 1) {
        start = len - 1;
    }

    // Make sure end <= len + 1 (exclusive)
    if (end > len + 1) {
        end = len + 1;
    }
    
    if (step > 0) {
        // Slice forwards
        for (int i = start; i < end; i += step) {
            *dest++ = *(orig + i);
        }
    } else if (step < 0) {
        // Slice backwards
        for (int i = start; i > end; i += step) {
            *dest++ = *(orig + i);
        }
    }
    *dest = '\0';
}

int main(void) {
    {
        char orig[] = "ABCDEFGHIJ";
        char dest[11];
        py_slice(orig, dest, 1, 3, 1);
        printf("Test 1\n");
        printf("Expected:BC\n");
        printf("Actual  :%s\n", dest);
        printf("\n");
    }

    {
        char orig[] = "ABCDEFGHIJ";
        char dest[11];
        py_slice(orig, dest, 0, 9, 1);
        printf("Test 2\n");
        printf("Expected:ABCDEFGHI\n");
        printf("Actual  :%s\n", dest);
        printf("\n");
    }

    {
        char orig[] = "ABCDEFGHIJ";
        char dest[11];
        py_slice(orig, dest, 0, 11, 1);
        printf("Test 3\n");
        printf("Expected:ABCDEFGHIJ\n");
        printf("Actual  :%s\n", dest);
        printf("\n");
    }

    {
        char orig[] = "ABCDEFGHIJ";
        char dest[11];
        py_slice(orig, dest, 0, 10, 2);
        printf("Test 4\n");
        printf("Expected:ACEGI\n");
        printf("Actual  :%s\n", dest);
        printf("\n");
    }

    {
        char orig[] = "ABCDEFGHIJ";
        char dest[11];
        py_slice(orig, dest, 0, 10, -2);
        printf("Test 5\n");
        printf("Expected:><\n");
        printf("Actual  :>%s<\n", dest);
        printf("\n");
    }

    {
        char orig[] = "ABCDEFGHIJ";
        char dest[11];
        py_slice(orig, dest, 10, 2, -2);
        printf("Test 6\n");
        printf("Expected:JHFD\n");
        printf("Actual  :%s\n", dest);
        printf("\n");
    }

    {
        char orig[] = "ABCDEFGHIJ";
        char dest[11];
        py_slice(orig, dest, 10, 2, 0);
        printf("Test 7\n");
        printf("Expected:><\n");
        printf("Actual  :>%s<\n", dest);
        printf("\n");
    }
    
    {
        char orig[] = "ABCDEFGHIJ";
        char dest[11];
        py_slice(orig, dest, 7, 2, -3);
        printf("Test 8\n");
        printf("Expected:HE\n");
        printf("Actual  :%s\n", dest);
        printf("\n");
    }
}
