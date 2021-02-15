#include <stdio.h>
#include <stdlib.h> // for atoi function
#include <ctype.h>  // for isdigit and isblank functions

int main(){
    char charHeight[50];
    int rows, columns, verify, height;

    printf("Insert the height between 1 and 8 to the Mario Structure.\n");

    while (verify != 1) {
        scanf(" %s", &charHeight);
        height = atoi(charHeight); //convert charHeight into an integer value and store in height
        if (height > 8 || height < 1 || isdigit(charHeight) == 1 || isblank(charHeight) == 1) {
            printf("Insert an valid height\n");
        } else {
            printf("The height is %d\n", height);
            verify++;
        }
    }

    for (rows = 0; rows < height; rows++) {
        for (columns = height -1; columns > rows; columns--) {
            printf(" ");
        }
        for (columns = -1; columns < rows; columns++) {
            printf("#");
        }
        printf("  ");
        for (columns = -1; columns < rows; columns++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}