#include <stdio.h>
#include <math.h> //log10 function
#include <stdlib.h> //calloc functions

int main(void) {
    int validCard, inputIsValid, inputLength, i, concat, sums, totalSums;
    int *cardNumber;
    long long int inputNumbers;

    //Initializing core variables
    validCard = inputIsValid = concat = sums = totalSums = 0;

    while (validCard < 1) {
        //Getting the card numbers
        printf("Insert the numbers of your credit card\n");
        inputIsValid = 0;
        while (inputIsValid < 1) { // Loop para validação de input
            if (scanf("%lld", &inputNumbers) == 1 && inputNumbers >= 0) {
                inputIsValid = 1;
            } else {
                printf("Insert an valid credit card number\n");
            }
        }
        //Calculating the size of the card numbers
        inputLength = 1 + ((int)log10((long long int)inputNumbers));
        //Creating an Dynamic array
        cardNumber = calloc(inputLength, sizeof(int));
        //Transforming integer to int array
        while (inputNumbers > 0) {
            cardNumber[i] = inputNumbers % 10;
            inputNumbers /= 10;
            i++;
        }
        //Validating the CardNumber (Luhn Algorithm)
            //Step 1
        for (i = 1; i < inputLength; i += 2) {   //Concatenate the digits of the numbers multiplied by 2
            if (cardNumber[i] * 2 < 10) {
                concat += cardNumber[i] * 2;
            } else {
                concat += 1 + ((cardNumber[i] * 2) % 10); 
            }
        }
            //Step 2
        for (i = 0; i < inputLength; i += 2) {     //adding the numbers that weren't multiplied by 2
            sums += cardNumber[i];
        }
            //Step 3
        totalSums = concat + sums; 
        if (totalSums % 10 == 0 && inputLength == 13 && cardNumber[inputLength - 1] == 4) {
            printf("VISA\n");
            validCard++;
        } else if (totalSums % 10 == 0 && inputLength == 16 && cardNumber[inputLength - 1] == 4) {
            printf("VISA\n");
            validCard++;
        } else if (totalSums % 10 == 0 && inputLength == 15 && cardNumber[inputLength - 1] == 3 ) {
            if (cardNumber[inputLength - 2] == 4 || cardNumber[inputLength - 2] == 7) {
                printf("AMEX\n");
                validCard++;
            } else {
                printf("INVALID\n");
            }
        } else if (totalSums % 10 == 0 && inputLength == 16 && cardNumber[inputLength - 1] == 5) {
            if(cardNumber[inputLength - 2] == 1 || cardNumber[inputLength - 2] == 2 || cardNumber[inputLength - 2] == 3 || cardNumber[inputLength - 2] == 4 || cardNumber[inputLength - 2] == 5) {
                printf("MASTERCARD\n");
                validCard++;
            } else {
                printf("INVALID\n");
            }
        } else {
            printf("INVALID\n");
        }
    }
}
/*
    Verify the Input
        Verify if the number have 13, 15 or 16 digits
        Verify if any of the inputs are letters
        Verify if any of the inputs are negative numbers
    Verify the card number
        Using Luhn's Algorithm
            Step 1 - Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together
            Step 2 - Add the sum to the sum of the digits that weren’t multiplied by 2.
            Step 3 - If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    Identifies the type of card:
        Visa - 13/16 digits, starts with 4 │ American Express(AMEX) - 15 digits, start with 34 or 37 | Master Card - 16 digits, starts with 51, 52, 53, 54 and 55 │       
Links used:
http://www.mathcs.emory.edu/~cheung/Courses/255/Syllabus/2-C-adv-data/dyn-array.html
https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
*/