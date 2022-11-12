#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x_pos;
    int y_pos;
} point;

/*
 Function that checks if two points are adjacent. 
 
 Returns true if:
 - both points share the same x pos with 1 point difference in y pos 
 - both points share the same y pos with 1 point difference in x pos

 Returns false otherwise
*/
bool is_adjacent(point a, point b) {
    if (a.x_pos == b.x_pos) {
        return (a.y_pos == b.y_pos + 1 || a.y_pos == b.y_pos - 1);
    }
    if (a.y_pos == b.y_pos) {
        return (a.x_pos == b.x_pos + 1 || a.x_pos == b.x_pos - 1);
    }
    return false;
}

/*
 
*/
void get_longest_sequence(int rows, int cols, int grid[][cols]) {
    // Iterate through the a x b grid once, in order to create an array where 
    // index corresponds to numbers and value corresponds to coordinates 

    // Example:
    // value: | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 
    // x-pos: | ? | ? | ? | ? | ? | ? | ? | ? | ? | 
    // y-pos: | ? | ? | ? | ? | ? | ? | ? | ? | ? | 
    point point_index[rows * cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols;j++) {
            point_index[grid[i][j] - 1].y_pos = i;
            point_index[grid[i][j] - 1].x_pos = j;
        }
    }

    // Iterate through point_index to find the longest adjacent streak
    int longest_streak = 1;
    int start_num = 1;
    
    int curr_streak = 1;
    int curr_num = 1;

    for (int i = 0; i < rows * cols - 1; i++) {
        if (is_adjacent(point_index[i], point_index[i + 1])) {
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
        get_longest_sequence(3, 3, grid);
    }

    {
        printf("\n\nTest case 2:\n");
        int grid[][2] = {
            {1, 2},
            {4, 5},
            {3, 6}
        };
        printf("Expected: 3 4 5 6\n");
        printf("Actual  : ");
        get_longest_sequence(3, 2, grid);
    }

    {
        printf("\n\nTest case 3:\n");
        int grid[][3] = {
            {1, 2, 9},
            {8, 3, 4},
            {7, 6, 5}
        };
        printf("Expected: 1 2 3 4 5 6 7 8\n");
        printf("Actual  : ");
        get_longest_sequence(3, 3, grid);
    }
}