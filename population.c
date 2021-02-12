#include <stdio.h>

int main(){
    int startPopulation, finalPopulation, year, newBorn, dead, verify;

    verify = startPopulation = finalPopulation = 0;

    do{
        printf("Insert the start population\n");
        scanf(" %i", &startPopulation);
        if(startPopulation < 9){
            printf("Start Population cant be less than 9\n");
        }else{
            printf("Start Population is %i\n", startPopulation);
            verify++;
        }
    }while (verify != 1);

    verify = 0;

    do{
        printf("Insert the final population\n");
        scanf(" %i", &finalPopulation);
        if(finalPopulation >= 9 && finalPopulation > startPopulation){
            printf("Final Population is %i\n", finalPopulation);
            verify++;
        }else{
            printf(finalPopulation < 9 ? "Final Population cant be less than 9\n": "Final Population cant be less than the Start Population\n");
        }
    }while (verify != 1);

    for(year = 0; startPopulation < finalPopulation; year++){
        newBorn = startPopulation / 3;
        dead = startPopulation / 4;
        startPopulation += (newBorn + (-dead));
        printf("newBorns: %i deaths: %i\n", newBorn, dead);
        printf("Start population %i\n", startPopulation);
    }

    printf("Years: %i\n", year);
    return 0;
}