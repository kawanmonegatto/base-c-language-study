#include <stdio.h>
#include <ctype.h> //For isalpha and isspace
#include <math.h> //For round

int main(void) {
    int i, letters, words, sentences;
    float index, l, s;
    char text[1000];
    //Initializing core variables
    letters = words = sentences = l = s = index = 0;
    //Getting inputs
    printf("Text: ");
    fgets(text, 1000, stdin);
    //Checking the text
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i]) != 0) {
            letters++;
        } else if (isspace(text[i]) != 0) {
            words++;
        } else if (text[i] == 46 || text[i] == 63 || text[i] == 33) {
            sentences++;
        }
    }
    printf("%d, %d, %d", letters, words, sentences);
    //Coleman-Liau index implimentation
    l = letters / (float)words * 100;
    s = sentences / (float)words * 100;
    index = round((0.0588 * l) - (0.296 * s) - 15.8);
    if (index >= 16) {
        printf("Grade 16+\n");
    } else if (index >= 1 && index < 16) {
        printf("Grade %.0f\n", index);
    } else {
        printf("Before Grade 1\n");
    }
}