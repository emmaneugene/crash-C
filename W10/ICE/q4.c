#include <stdio.h>

typedef struct {
    char name[100];
    int age;
    char gender; // either 'M' or 'F'
} person;

person get_youngest_female(person people[] , int person_count) {
    // Get index of first female, if one exists
    int index = 0;
    while (people[index].gender != 'F' && index < person_count) {
        index++;
    }

    // If no female, return "Not found"
    if (index == person_count) {
        person youngest_female = {"Not found", 0, 'F'};
        return youngest_female;
    }

    person youngest_female = people[index];

    // Iterate from index onwards
    for (int i = index; i < person_count; i++) {
        // Compare their age
        if (people[i].gender == 'F' && youngest_female.age > people[i].age) {
            youngest_female = people[i];
        }
    }

    return youngest_female;
}

int main(void) {
    {
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

        person oldest = get_youngest_female(all, sizeof(all)/sizeof(person));
        printf("Test 1\n");
        printf("Expected:Jolene\n");
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
            {"Vienne", 8, 'F'},
            {"Sue", 8, 'F'}};

        person oldest = get_youngest_female(all, sizeof(all)/sizeof(person));
        printf("Test 2\n");
        printf("Expected:Vienne\n");
        printf("Actual  :%s\n", oldest.name);
        printf("\n");
    }

        {
        person all[] = {
            {"Amy", 4, 'F'}, // Should be F
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

        person oldest = get_youngest_female(all, sizeof(all)/sizeof(person));
        printf("Test 3\n");
        printf("Expected:Amy\n");
        printf("Actual  :%s \n", oldest.name);
        printf("\n");
    }
}
