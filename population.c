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
        if(finalPopulation >= 9){
            if(startPopulation > finalPopulation){
            printf("Final Population cant be less than Start Population\n");
            }else{
                printf("Final Population is %i\n", finalPopulation);
                verify++;
            }
        }else{
            printf("Final Population cant be less than 9\n");
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