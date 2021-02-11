#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    int height = 0;
    int rows, columns, verify;

    printf("Insert the height between 1 and 8 to the Mario Structure.\n");

    while(verify != 1){
        scanf(" %d", &height);
        if(height > 8 || height < 1){
            printf("Insert an valid number\n");
        }else{
            printf("The height is %d\n", height);
            verify++;
        }
    }

    for(rows = 0; rows < height; rows++){
        for(columns = height -1; columns > rows; columns--){
            printf(" ");
        }
        for(columns = -1; columns < rows; columns++){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}