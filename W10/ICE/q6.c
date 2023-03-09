#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char name[100];
    int age;
} person;

bool is_equals(person *p1, person *p2) {
    char *p1_name = p1->name;
    char *p2_name = p2->name;

    // Check both names
    if (strcmp(p1_name, p2_name) != 0) {
        return false;
    }
    // Now we only need to check age
    return (p1->age == p2->age);
}

int main(void) {
    {
        printf("Test 1\n");
        person p1 = {"amy", 12};
        person p2 = {"amy", 12};
        printf("Expected:True\n");
        printf("Actual  :%s\n", is_equals(&p1, &p2) ? "True" : "False");
        printf("\n");
    }

    {
        printf("Test 2\n");
        person p1 = {"Amy", 12};
        person p2 = {"amy", 12};
        printf("Expected:False\n");
        printf("Actual  :%s\n", is_equals(&p1, &p2) ? "True" : "False");
        printf("\n");
    }

    {
        printf("Test 3\n");
        person p1 = {"Sue", 12};
        person p2 = {"amy", 12};
        printf("Expected:False\n");
        printf("Actual  :%s\n", is_equals(&p1, &p2) ? "True" : "False");
        printf("\n");
    }

        {
        printf("Test 4\n");
        person p1 = {"amy", 12};
        person p2 = {"amy", 13};
        printf("Expected:False\n");
        printf("Actual  :%s\n", is_equals(&p1, &p2) ? "True" : "False");
        printf("\n");
    }
}
