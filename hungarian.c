#include <stdio.h>
#include <stdlib.h>

#define MAX = 32

unsigned short int test = 32;

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

            testGrid[i][j] = 0;

        }
    }

    // printf("%i" , test);

    printf("%hu" , testGrid[0][0]);

    // for (int index = 0 ; index < test ; index++){  

    // }

    return 0;

}