#include <stdio.h>
#include <math.h> //log10 function
#include <stdlib.h> //calloc, itoa functions
#include <ctype.h> //isdigit function

int main(void) {
    int inputLength, i, start, end, quotient, sums, a, validCard, inputIsValid;
    int *cardNumber, *cardNumberReversed;
    long long int inputNumbers;
    char *cardNumberChar;

    // Initializing core variables
    inputNumbers = i = start = quotient = sums = validCard = inputIsValid = 0;
    
    printf("Insert the numbers of your credit card\n");
    while (validCard < 1) {
        // Getting the card numbers
        while (inputIsValid != 1) { // Loop para validação de input
            scanf("%lld", &inputNumbers);
            // Calculating the size of the card numbers
            inputLength = 1 + ((int)log10((long long int)inputNumbers));
            // Creating an Dynamic array
            cardNumber = calloc(inputLength, sizeof(int));
            cardNumberChar = calloc(inputLength, sizeof(char));
            cardNumberReversed = calloc(inputLength, sizeof(int));
            // Transforming integer to int array
            while (inputNumbers > 0) {
                cardNumber[i] = inputNumbers % 10;
                inputNumbers /= 10;
                i++;
            }
            // Verifying if the array only contain numbers
            for (i = 0; i < inputLength; i++) {
                _itoa(cardNumber[i], cardNumberChar[i], 10);
                printf("%s-", cardNumberChar[i]);
                if (!isdigit(cardNumberChar[i] == 0 || cardNumber[i] < 0)) {
                    printf("Insert an Valid Card Number\n");
                } else {
                    validCard = 1;
               }
            }
        }
        // Reversing the int array
        end = inputLength - 1;
        for (start = 0; start < inputLength; start++) {
            cardNumberReversed[end] = cardNumber[start];
            end--;
        }
        // Validating the CardNumber (Luhn Algorithm)
        for (i = 0; i < inputLength; i += 2) {     // Step 1
            quotient += cardNumberReversed[i] * 2;
        }
        for (i = 0; i < inputLength; i++) {     // Step 2
            if (cardNumberReversed[i] % 2 == 0) {
                sums += cardNumberReversed[i];
            }
        }
        a = quotient + sums;    // Step 3
        if (a / 2 == 0 || inputLength == 13) {
            printf("Valid Visa Card\n");
            validCard++;
        } else if (a / 2 == 0 || inputLength == 15) {
            printf("Valid AMEX Card\n");
            validCard++;
        } else if (a / 2 == 0 || inputLength == 16) {
            printf("Valid MasterCard Card\n");
            validCard++;
        } else {
            printf("Invalid Card Number\n");
        }
        fflush(stdin);
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
        Visa - 13 │ American Express(AMEX) - 15 digits | Master Card - 16 digits │
Links used:
http://www.mathcs.emory.edu/~cheung/Courses/255/Syllabus/2-C-adv-data/dyn-array.html
https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
*/