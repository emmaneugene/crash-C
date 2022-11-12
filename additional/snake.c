#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x_pos;
    int y_pos;
} point;

bool is_adjacent(point a, point b) {
    if (a.x_pos == b.x_pos) {
        return (a.y_pos == b.y_pos + 1 || a.y_pos == b.y_pos - 1);
    }
    if (a.y_pos == b.y_pos) {
        return (a.x_pos == b.x_pos + 1 || a.x_pos == b.x_pos - 1);
    }
    return false;
}

void get_longest_snake(int rows, int cols, int grid[][cols]) {
    // Iterate through the a x b grid once, in order to create an array of points

    // Start from smallest integer (always 1)

    // O(ab + ab) complexity ~ O(ab)

    // value: | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 
    // x-pos: | ? | ? | ? | ? | ? | ? | ? | ? | ? | 
    // y-pos: | ? | ? | ? | ? | ? | ? | ? | ? | ? | 
    point pointarray[rows * cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols;j++) {
            pointarray[grid[i][j] - 1].y_pos = i;
            pointarray[grid[i][j] - 1].x_pos = j;
        }
    }

    // Look for the longest valid streak
    int longest_streak = 1;
    int start_num = 1;
    
    int curr_streak = 1;
    int curr_num = 1;

    for (int i = 0; i < rows * cols - 1; i++) {
        if (is_adjacent(pointarray[i], pointarray[i + 1])) {
            curr_streak++;
        } else {
            if (curr_streak > longest_streak) {
                longest_streak = curr_streak;
                start_num = curr_num;
            }
            curr_streak = 1;
            curr_num = i + 2;
        }
    }

    if (curr_streak > longest_streak) {
        longest_streak = curr_streak;
        start_num = curr_num;
    }

    for (int i = 0; i < longest_streak; i++) {
        printf("%d ", start_num++);
    }
    printf("\n");
       
}


int main(void) {
    {
        printf("Test case 1:\n");
        int grid[][3] = {
            {5, 6, 7},
            {4, 3, 2},
            {9, 1, 8}
        };
        printf("Expected: 2 3 4 5 6 7\n");
        printf("Actual  : ");
        get_longest_snake(3, 3, grid);
    }

    {
        printf("Test case 2:\n");
        int grid[][2] = {
            {1, 2},
            {4, 5},
            {3, 6}
        };
        printf("Expected: 3 4 5 6\n");
        printf("Actual  : ");
        get_longest_snake(3, 2, grid);
    }

    {
        printf("Test case 3:\n");
        int grid[][3] = {
            {1, 2, 9},
            {8, 3, 4},
            {7, 6, 5}
        };
        printf("Expected: 1 2 3 4 5 6 7 8\n");
        printf("Actual  : ");
        get_longest_snake(3, 3, grid);
    }
}