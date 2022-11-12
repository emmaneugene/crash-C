#include <stdio.h>
#include <stdbool.h>

int game_won(int positions[]) {
    // check rows
    for (int i = 0; i < 9; i += 3) {
        if (positions[i] == positions[i + 1] && positions[i + 1] == positions[i + 2]) {
            return positions[i];
        } 
    }
    // check cols
    for (int i = 0; i < 3; i++) {
        if (positions[i] == positions[i + 3] && positions[i + 3] == positions[i + 6]) {
            return positions[i];
        } 
    }
    // check diagonals
    if (positions[0] == positions[4] && positions[4] == positions[8]) {
        return positions[0];
    }

    if (positions[2] == positions[4] && positions[4] == positions[6]) {
        return positions[2];
    }

    return 0;
}

bool game_over(int positions[]) {
    for (int i = 0; i < 9; i++) {
        if (positions[i] == 0) {
            return false;
        }
    }
    return true;
}

void print_board(int positions[]) {
    // 0 = ' ', 1 = 'X', 2 = 'O'
    printf("=======\n");
    
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) {
            printf("|");
        }

        switch (positions[i]) {
            case 1:
                printf("X");
                break;
            case 2:
                printf("O");
                break;
            default:
                printf(" ");
        }

        printf("|");

        if (i % 3 == 2) {
            printf("\n");
        }
    }
    printf("=======\n");

}

int main(void) {
    int positions[9] = {0};

    printf("Players, Choose positions 0 to 8:\n");
    printf("=======\n|1|2|3|\n|4|5|6|\n|7|8|9|\n=======\n");

    int turns = 0;
    int position;

    while (!game_won(positions) && !game_over(positions)) {
        do {
            printf("Player %c, choose position :", turns % 2 == 0 ? 'X' : 'O');
            scanf("%d", &position);
        } while (positions[position - 1]);
        
        positions[position - 1] = turns % 2 + 1;
        print_board(positions);
        printf("\n");
        
        turns++;
    }

    switch (game_won(positions)) {
    case 1:
        printf("Player X wins!\n");
        break;
    case 2:
        printf("Player O wins!\n");
        break;
    default:
        printf("This game is a draw!\n");
    }
}