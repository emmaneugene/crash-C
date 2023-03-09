#include <stdio.h>


int main(void) {
    char nric[10];

    printf("enter NRIC:");
    scanf("%s", nric);

    int checksum = 0;

    if (nric[0] == 'T' || nric[0] == 'G') {
        checksum += 4;
    }


    checksum += (nric[1] - '0') * 2;
    checksum += (nric[2] - '0') * 7;
    checksum += (nric[3] - '0') * 6;
    checksum += (nric[4] - '0') * 5;
    checksum += (nric[5] - '0') * 4;
    checksum += (nric[6] - '0') * 3;
    checksum += (nric[7] - '0') * 2;

    checksum %= 11;

    char last_letter = '\0';

    if (nric[0] == 'S' || nric[0] == 'T') {
        switch (checksum)
        {
        case 0:
            last_letter = 'J';
            break;
        case 1:
            last_letter = 'Z';
            break;
        case 2:
            last_letter = 'I';
            break;
        case 3:
            last_letter = 'H';
            break;
        case 4:
            last_letter = 'G';
            break;
        case 5:
            last_letter = 'F';
            break;
        case 6:
            last_letter = 'E';
            break;
        case 7:
            last_letter = 'D';
            break;
        case 8:
            last_letter = 'C';
            break;
        case 9:
            last_letter = 'B';
            break;
        case 10:
            last_letter = 'A';
            break;
        }
    } else if (nric[0] == 'F' || nric[0] == 'G') {
        switch (checksum)
        {
        case 0:
            last_letter = 'X';
            break;
        case 1:
            last_letter = 'W';
            break;
        case 2:
            last_letter = 'U';
            break;
        case 3:
            last_letter = 'T';
            break;
        case 4:
            last_letter = 'R';
            break;
        case 5:
            last_letter = 'Q';
            break;
        case 6:
            last_letter = 'P';
            break;
        case 7:
            last_letter = 'N';
            break;
        case 8:
            last_letter = 'M';
            break;
        case 9:
            last_letter = 'L';
            break;
        case 10:
            last_letter = 'K';
            break;
        }
    }

    printf("%s\n", nric[8] == last_letter ? "valid" : "invalid");
}
