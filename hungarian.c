#include <stdio.h>
#include <stdlib.h>

#define MAX = 32

unsigned short int test = 32;

void outPutAll(unsigned short int **inGrid){

    

}

int main(){

    unsigned short int dimen;

    scanf("%hu" , &dimen);

    unsigned short int **testGrid = malloc(dimen * sizeof(unsigned short int *));

    if (!testGrid){
        return 1;
    }

    for ( int i = 0 ; i < dimen ; i++){

        testGrid[i] = malloc(dimen * sizeof(unsigned short int*));

        if (!testGrid[i]){

            return 1;

        }

    }

    for (int i = 0 ; i < dimen ; i++){
        for ( int j = 0 ; j < dimen ; j++){

            unsigned short int tempInput;

            scanf("%hu" , &tempInput);

            testGrid[i][j] = tempInput;

        }
    }

    // printf("%i" , test);

    printf("%hu" , testGrid[0][0]);

    // for (int index = 0 ; index < test ; index++){  

    // }

    free(testGrid);

    return 0;

}