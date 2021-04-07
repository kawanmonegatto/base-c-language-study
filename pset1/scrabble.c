#include <stdio.h>
//Function Prototype
int ScoreCalc(char playerInput[], int pointsValue[]);

int main() {
    char player1[30], player2[30];
    int i, ii, points1, points2, pointsIndex[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    //Initializing core variables
    points1 = points2 = 0;
    //Inputs
    printf("Player 1: ");
    scanf("%s", player1);
    printf("Player 2: ");
    scanf("%s", player2);
    //Calling the score calculation function
    points1 = ScoreCalc(player1, pointsIndex);
    points2 = ScoreCalc(player2, pointsIndex);
    if (points1 > points2) {
        printf("Player 1 wins");
    } else if (points1 < points2) {
        printf("Player 2 wins");
    } else {
        printf("Tie!");
    }
}

int ScoreCalc(char playerInput[], int pointsValue[]){
    int i, ii, totalPoints, numberASCII;
    //Initializing core variables
    numberASCII = 65;
    totalPoints = 0;
    //Calculating the score for each player
    for (i = 0; playerInput[i] != '\0'; i++) {
        for (ii = 0; ii < 26; ii++){
            if ((int)playerInput[i] == (numberASCII + ii) || (int)playerInput[i] == (numberASCII + 32 + ii)) { //Verifying the input as ASCII numerical value
                totalPoints += pointsValue[ii];
                break;
            }
        }
    }
    return totalPoints;
}
/*
    Consulting table
    { 1,   3,   3,   2,   1,   4,   2,   4,   1,   8,   5,   1,   3,   1,   1,   3,  10,   1,   1,   1,   1,   4,   4,   8,   4,   10}
    {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}
*/