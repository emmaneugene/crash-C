#include <stdio.h>

typedef struct {
    char name[100];
    int age;
    char gender; // either 'M' or 'F'
} person;

person get_oldest_male(person people[] , int person_count) {
    // Get index of first male, if one exists
    int index = 0;
    while (people[index].gender != 'M' && index < person_count) {
        index++;
    }

    // If no male, return "Not found"
    if (index == person_count) {
        person oldest_male = {"Not found", 0, 'M'};
        return oldest_male;
    }

    person oldest_male = people[index];

    // Iterate from index onwards
    for (int i = index; i < person_count; i++) {
        // Compare their age
        if (people[i].gender == 'M' && oldest_male.age <= people[i].age) {
            oldest_male = people[i];
        }
    }

    return oldest_male;
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

        person oldest = get_oldest_male(all, sizeof(all)/sizeof(person));
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
            {"Shaun", 38, 'M'},
            {"Leo", 38, 'M'}};

        person oldest = get_oldest_male(all, sizeof(all)/sizeof(person));
        printf("Test 2\n");
        printf("Expected:Leo\n");
        printf("Actual  :%s\n", oldest.name);
        printf("\n");
    }

        {
        person all[] = {
            {"Lucy", 88, 'F'},
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

        person oldest = get_oldest_male(all, sizeof(all)/sizeof(person));
        printf("Test 3\n");
        printf("Expected:Zac\n");
        printf("Actual  :%s \n", oldest.name);
        printf("\n");
    }

            {
        person all[] = {
            {"Jolene", 13, 'F'},
            {"Jiwen", 19, 'F'},
            {"Amanda", 38, 'F'}};

        person oldest = get_oldest_male(all, sizeof(all)/sizeof(person));
        printf("Test 3\n");
        printf("Expected:Not found\n");
        printf("Actual  :%s \n", oldest.name);
        printf("\n");
    }
}