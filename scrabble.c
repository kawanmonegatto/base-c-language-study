#include <stdio.h>
#include <string.h> //for strcmp

int main() {
    char player1[20], player2[20];
    int i, ii, points1, points2, numberASCII, pointsIndex[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    // char lettersIndex [26][26] = {
    //     {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
    //     {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}
    // };

    points1 = points2 = 0;
    numberASCII = 65;
    //Inputs
    printf("Player 1: ");
    scanf("%s", player1);
    printf("Player 2: ");
    scanf("%s", player2);
    //Verifying the character
    for (i = 0; player1[i] != '\0'; i++) {
        for (ii = 0; ii < 26; ii++){
            if ((int)player1[i] == (numberASCII + ii) || (int)player1[i] == (numberASCII + 32 + ii)) { //Verifying the input as ASCII numerical value
                points1 += pointsIndex[ii];
                break;
            }
        }
    }
    for (i = 0; player2[i] != '\0'; i++) {
        for (ii = 0; ii < 26; ii++){
            if ((int)player2[i] == (numberASCII + ii) || (int)player2[i] == (numberASCII + 32 + ii)) { //Verifying the input as ASCII numerical value
                points2 += pointsIndex[ii];
                break;
            }
        }
    }
    if (points1 > points2) {
        printf("Player 1 wins");
    } else {
        printf("Player 2 wins");
    }
}