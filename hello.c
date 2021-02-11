#include <stdio.h>

void main (void){
    char name[20];

    printf("Whats is your name?");
    scanf("%s", name);
    printf("Hello, %s", name);
}