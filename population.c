#include <stdio.h>

int main(){
    int startPopulation, endPopulation, year;
    int born, dead;

    startPopulation = 1000;
    
    born = startPopulation / 3;
    dead = startPopulation / 4;

    printf("%i\n%i\n", born, dead);

    return 0;
}