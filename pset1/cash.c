#include <stdio.h>
#include <stdlib.h>

int main() {
    float change;
    int totalCoins, quarterCoin, dimeCoin, nickelCoin, pennyCoin, counter, inputIsValid;

    totalCoins = quarterCoin = dimeCoin = nickelCoin = pennyCoin = counter = inputIsValid = 0;
    change = 0.00;

    printf("For how much change you need for?\n");
    while (inputIsValid != 1) { // Loop para validação de input
        if (scanf("%f", &change) == 1 && change >= 0) {
            inputIsValid = 1;
        } else {
            printf("Insert an valid number\n");
            fflush(stdin);
        }
    }
    printf("You need change for: %.2f\n", change);
    while (counter != 1) { // Loop de cálculo de troco
        if (change >= 0.25) {
            change -= 0.25;
            quarterCoin++;
        } else if (change < 0.25 && change > 0.099) {
            change -= 0.10;
            dimeCoin++;
        } else if (change < 0.10 && change > 0.049) {
            change -= 0.05;
            nickelCoin++;
        } else if (change < 0.05 && change > 0.009) {
            change -= 0.01;
            pennyCoin++;
        } else {
            counter++;
        }
    }
    totalCoins = quarterCoin + dimeCoin + nickelCoin + pennyCoin;
    printf("Total Coins: %d\n Quarters: %d\n Dimes: %d\n Nickels: %d\n Pennies: %d\n", totalCoins, quarterCoin, dimeCoin, nickelCoin, pennyCoin);
    return 0;
}