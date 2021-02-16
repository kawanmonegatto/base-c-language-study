#include <stdio.h>
#include <math.h>

int main() {
    float owe, change, quarter, dime, nickel, penny;
    int coinCounter;

    quarter = 0.25;
    dime = 0.10;
    nickel = 0.05;
    penny = 0.01;

    printf("For how much change you need for?\n");
    scanf(" %f", &change);
    
    if (change > 0) {
        printf("You need change for %.2f\n", change);
        if (owe = 0) {
            owe = fmodf(change, quarter) * 100;
            coinCounter++;
        } else if (owe = 0) {
            owe = fmodf(change, dime) * 100;
            coinCounter++;
        } else if (owe = 0) {
            owe = fmodf(change, nickel) * 100;
            coinCounter++;
        } else if (owe = 0) {
            owe = fmodf(change, penny) * 100;
            coinCounter++;
        }
    } else {
        printf("Insert an valid number\n");
    }
    printf("%d", coinCounter);
    return 0;
}

    /*  todo list on this program

        int cents = round(dollars * 100);

        calculate the total of coins as an int number, for exempla "total: 9 coins"
        check if the input is:
        -1.00 (or other negative numbers)?
        0.00?
        0.01 (or other positive numbers)?
        letters or words?
        no input at all, when you only hit Enter?
    */