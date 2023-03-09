#include <stdio.h>

void move_robot(int position[], char moves[], int len) {
    int x = position[0];
    int y = position[1];

    int idx = 0;
    while (idx < len) {
        int count = 1;
        if (moves[idx] >= '0' && moves[idx] <= '9') {
            count = moves[idx] - '0';
            idx++;
        }

        char direction = moves[idx];

        switch (direction)
        {
            case 'N':
                y += count;
                break;
            case 'S':
                y -= count;
                break;
            case 'E':
                x += count;
                break;
            case 'W':
                x -= count;
                break;
            default:
                break;
        }
        idx++;
    }

    position[0] = x;
    position[1] = y;
}

// ------------------------TESTS------------------------

int main(void) {
    char moves1[] = {'N', 'N', 'N', 'S', 'S'};
    int position1[] = {0, 0};
    move_robot(position1, moves1, sizeof(moves1)/sizeof(char));
    printf("Expected: (0,1)\n");
    printf("Actual  : ");
    printf("(%d,%d)\n", position1[0], position1[1]);

    char moves2[] = {'3', 'N', '2', 'S'};
    int position2[] = {0, 0};
    move_robot(position2, moves2, sizeof(moves2)/sizeof(char));
    printf("Expected: (0,1)\n");
    printf("Actual  : ");
    printf("(%d,%d)\n", position2[0], position2[1]);


    char moves3[] = {'3', 'N', '6', 'E', 'S', '4', 'W'};
    int position3[] = {0, 0};
    move_robot(position3, moves3, sizeof(moves3)/sizeof(char));
    printf("Expected: (2,2)\n");
    printf("Actual  : ");
    printf("(%d,%d)\n", position3[0], position3[1]);

    char moves4[] = {'6', 'W', '4', 'S', 'S', 'N', 'W'};
    int position4[] = {5, 12};
    move_robot(position4, moves4, sizeof(moves4)/sizeof(char));
    printf("Expected: (-2,8)\n");
    printf("Actual  : ");
    printf("(%d,%d)\n", position4[0], position4[1]);
}
