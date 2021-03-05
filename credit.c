#include <stdio.h>
#include <math.h> //log10 function
#include <stdlib.h> //calloc functions

int main(void) {
    int inputLength, i, start, end, quotient, sums, a, validCard, inputIsValid, quotientSums, totalSums;
    int *cardNumber, *cardNumberReversed;
    long long int inputNumbers;

    //Initializing core variables
    inputNumbers = i = start = quotient = sums = validCard = inputIsValid = 0;

    while (validCard < 1) {
        //Getting the card numbers
        inputIsValid = 0;
        printf("Insert the numbers of your credit card\n");
        while (inputIsValid != 1) { // Loop para validação de input
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
        cardNumberReversed = calloc(inputLength, sizeof(int));
        //Transforming integer to int array
        while (inputNumbers > 0) {
            cardNumber[i] = inputNumbers % 10;
            inputNumbers /= 10;
            i++;
        }
        //Reversing the int array
        end = inputLength - 1;
        for (start = 0; start < inputLength; start++) {
            cardNumberReversed[end] = cardNumber[start];
            end--;
        }
        //Validating the CardNumber (Luhn Algorithm)
        for (i = 0; i < inputLength; i += 2) {   //Step 1
            quotient += cardNumberReversed[i] * 2;
        }
        while (quotient != 0) {
            quotientSums += quotient % 10;
            quotient / 10;
        }
        for (i = 1; i < inputLength; i += 2) {     //Step 2
            sums += cardNumberReversed[i];
        }
        totalSums = quotientSums + sums; //Step 3
        if (a % 10 == 0 && inputLength == 13 && cardNumberReversed[0] == 4) {
            printf("VISA\n");
            validCard++;
        } else if (a % 10 == 0 && inputLength == 16 && cardNumberReversed[0] == 4) {
            printf("VISA\n");
            validCard++;
        } else if (a % 10 == 0 && inputLength == 15 && cardNumberReversed[0] == 3 ) {
            if (cardNumberReversed[1] == 4 || cardNumberReversed[1] == 7) {
                printf("AMEX\n");
                validCard++;
            }
        } else if (a % 10 == 0 && inputLength == 16 && cardNumberReversed[0] == 5) {
            if(cardNumberReversed[1] == 1 || cardNumberReversed[1] == 2 || cardNumberReversed[1] == 3 || cardNumberReversed[1] == 4 || cardNumberReversed[1] == 5) {
                printf("MASTERCARD\n");
                validCard++;
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