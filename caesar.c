#include <stdio.h>
#include <ctype.h> //For isalpha function
#include <string.h> //For strlen ffunction

int main(void) {
    char plainText[20], cipherText[20];
    int key, cipherKey, keyIsValid, plainIsValid, inputTextSize, i, ii;
    float n;
    char alphabet[2][26] = {
        {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
        {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}
    };
    //Initializing variables
    key = cipherKey = keyIsValid = plainIsValid = inputTextSize = n = 0;
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
        if (isalpha(plainText[i]) != 0) {
        } else {
            printf("Invalid input\n");
            break;
        }
    }
    // Obtaining the Cipher Key
    for (i = 0; i < inputTextSize; i++) {
        printf("I: %d", i);
        if (isupper(plainText[i]) != 0) {
            ii = 0;
            do {
                cipherKey = (ii + key) % 26;
                cipherText[i] = alphabet[1][cipherKey];
                cipherKey = 0;                
                ii++;
            } while (plainText[i] != alphabet[0][ii]);
        } else if (islower(plainText[i]) != 0) {
            ii = 0;
            do {
                cipherKey = (ii + key) % 26;
                cipherText[i] = alphabet[1][cipherKey];
                cipherKey = 0;                
                ii++;
            } while (plainText[i] != alphabet[0][ii]);
            // for (ii = 0; (plainText[i] != alphabet[1][ii]); ii++) {
            //     cipherKey = (ii + key) % 26;
            //     cipherText[i] = alphabet[1][cipherKey];
            //     cipherKey = 0;                
            // }
        } else {
            printf("ERROR");
        }
    }
    printf("Plain Text: %s", plainText);
    printf("Cipher Text: %s", cipherText);
}
/*
    ci = (pi + k) % 26
*/