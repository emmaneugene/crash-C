#include <stdio.h>

typedef struct {
    char name[100];
    int age;
    char gender; // either 'M' or 'F'
} person;

person get_oldest_person(person people[] , int person_count) {
    person oldest = people[0];

    // Iterate over people
    for (int i = 1; i < person_count; i++) {
        // Compare their age
        if (oldest.age < people[i].age) {
            oldest = people[i];
        }
    }

    return oldest;
}

int main(void) {
    {
        // Array of structs
        person all[] = {
            {"Shaun", 38, 'M'},
            {"Leslie", 34, 'M'},
            {"Dean", 32, 'M'},
            {"Sebastian", 18, 'M'},
            {"Gabriel", 19, 'M'},
            {"Xiao Wei", 38, 'F'},
            {"Cheryl", 17, 'F'},
            {"Sunita", 14, 'F'},
            {"Jolene", 13, 'F'},
            {"Jiwen", 19, 'F'},
            {"Amanda", 38, 'F'}};

        person oldest = get_oldest_person(all, sizeof(all)/sizeof(person));
        printf("Test 1\n");
        printf("Expected:Shaun\n");
        printf("Actual  :%s\n", oldest.name);
        printf("\n");
    }

    {
        person all[] = {
            {"Leslie", 34, 'M'},
            {"Dean", 32, 'M'},
            {"Sebastian", 18, 'M'},
            {"Gabriel", 19, 'M'},
            {"Xiao Wei", 38, 'F'},
            {"Cheryl", 17, 'F'},
            {"Sunita", 14, 'F'},
            {"Jolene", 13, 'F'},
            {"Jiwen", 19, 'F'},
            {"Amanda", 38, 'F'},
            {"Shaun", 38, 'M'}};

        person oldest = get_oldest_person(all, sizeof(all)/sizeof(person));
        printf("Test 2\n");
        printf("Expected:Xiao Wei\n");
        printf("Actual  :%s\n", oldest.name);
        printf("\n");
    }

        {
        person all[] = {
            {"Leslie", 34, 'M'},
            {"Dean", 32, 'M'},
            {"Sebastian", 18, 'M'},
            {"Gabriel", 19, 'M'},
            {"Xiao Wei", 38, 'F'},
            {"Cheryl", 17, 'F'},
            {"Sunita", 14, 'F'},
            {"Jolene", 13, 'F'},
            {"Jiwen", 19, 'F'},
            {"Amanda", 38, 'F'},
            {"Zac", 39, 'M'}};

        person oldest = get_oldest_person(all, sizeof(all)/sizeof(person));
        printf("Test 3\n");
        printf("Expected:Zac\n");
        printf("Actual  :%s\n", oldest.name);
        printf("\n");
    }
}
