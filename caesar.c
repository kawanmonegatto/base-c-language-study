#include <stdio.h>
#include <ctype.h> //For isalpha, isupper, islower function
#include <string.h> //For strlen function

int main(void) {
    char plainText[20], cipherText[20];
    int key, cipherKey, keyIsValid, plainIsValid, inputTextSize, i, ii;
    char alphabet[2][26] = {
        {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
        {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}
    };
    //Initializing variables
    key = cipherKey = keyIsValid = plainIsValid = inputTextSize = 0;
    //Getting Key input and validating
    printf("Key: ");
    while (keyIsValid != 1) {
        if (scanf("%d", &key) == 1) {
            keyIsValid = 1;
            key++;
        } else {
            printf("Input is invalid\n");
            fflush(stdin);
        }
    fflush(stdin);
    }
    // Getting and Validating Plain Text Input
    printf("Plaintext: ");
    fgets(plainText, sizeof(plainText), stdin);
    inputTextSize = strlen(plainText) - 1;
    for (i = 0; i < inputTextSize; i++) {
        if (isalpha(plainText[i]) != 0 || isspace(plainText[i]) != 0 || ispunct(plainText[i]) != 0) {
            // empty
        } else {
            printf("Invalid input\n");
            break;
        }
    }
    // Obtaining the Cipher Key
    for (i = 0; i < inputTextSize; i++) {
        if (isupper(plainText[i]) != 0) {
            ii = 0;
            do {
                cipherKey = (ii + key) % 26;
                cipherText[i] = alphabet[0][cipherKey];
                cipherKey = 0;                
                ii++;
                cipherText[i++] = '\0';
                printf("%d", i);
            } while (plainText[i] != alphabet[0][ii]);
        } else if (islower(plainText[i]) != 0) {
            ii = 0;
            do {
                cipherKey = (ii + key) % 26;
                cipherText[i] = alphabet[1][cipherKey];
                cipherKey = 0;                
                ii++;
                cipherText[i++] = '\0';
            } while (plainText[i] != alphabet[1][ii]);
        } else {
            printf("ERROR");
        }
    }
    printf("\nPlain Text: %s\n", plainText);
    printf("Cipher Text: %s\n", cipherText);
}
/*
    ci = (pi + k) % 26
*/