#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

unsigned short int test = 32;

void outPutAll(unsigned short int **inGrid , int inDimensions){

    printf("-------\n");

    for (int i = 0 ; i < inDimensions ; i++){

        for (int k = 0 ; k < inDimensions ; k++){

            printf("|%i| " , inGrid[i][k]);

        }

        printf("\n");

    }

}

void reduce(unsigned short int **inputGrid , int inputDimensions){

    for ( int i = 0 ; i < inputDimensions ; i++ ){

        int tempSmallest = inputGrid[i][0];

        for ( int k = 0 ; k < inputDimensions ; k++ ){

            if (inputGrid[i][k] < tempSmallest){

                tempSmallest = inputGrid[i][k];

            }

        }

        for (int k = 0 ; k < inputDimensions ; k++){

            inputGrid[i][k] -= tempSmallest;

        }
            
    }

    printf("Reduced rows only:\n");
    outPutAll(inputGrid , inputDimensions);

    for ( int i = 0 ; i < inputDimensions ; i++){

        int tempSmallest = inputGrid[0][i];

        for (int k = 0 ; k < inputDimensions ; k++){

            if (inputGrid[k][i] < tempSmallest){

                tempSmallest = inputGrid[k][i];

            }

        }

        for ( int k = 0 ; k < inputDimensions ; k++){

            inputGrid[k][i] -= tempSmallest;

        }

    }

    printf("Reduced rows and columns:\n");
    outPutAll(inputGrid , inputDimensions);

}

void augment(unsigned short int **inputGrid , int inputDimensions , unsigned short int **inputReference){

    int numberOfLines = 0;

    bool isOptimal = false;

    while (isOptimal == false){

        int numberOfZerosRows;

        int numberOfZerosColumns;

        for (int a = 0 ; a < inputDimensions ; a++){

            for (int b = 0 ; b < inputDimensions ; b++){

                inputReference[a][b] = 0;

            }

        }

        for (int i = 0 ; i < inputDimensions ; i++){

            numberOfZerosRows = 0;
            numberOfZerosColumns = 0;

            for (int k = 0 ; k < inputDimensions ; k++){

                if (inputGrid[i][k] == 0){

                    numberOfZerosRows += 1;

                } else if (inputGrid[k][i] == 0){

                    numberOfZerosColumns += 1;

                }

            }

            if (numberOfZerosColumns > numberOfZerosRows){

                for (int j = 0 ; j < inputDimensions ; j ++){

                    inputReference[j][i] += 1;

                }

                numberOfLines += 1;

            } else if (numberOfZerosColumns == numberOfZerosRows || numberOfZerosColumns < numberOfZerosRows){

                for (int j = 0 ; j < inputDimensions ; j++){

                    inputReference[i][j] += 1;

                }

                numberOfLines += 1;

            }


        }

        if (numberOfLines == inputDimensions){

            isOptimal = true;

        } else {

            int e;

            for ( int a = 0 ; a < inputDimensions ; a++){ // To find a starting value for e in case smallest is larger than default value given.

                for (int b = 0 ; b < inputDimensions ; b++){

                    if (inputReference[a][b]){

                        e == inputGrid[a][b];

                    }

                }

            }

            for (int i = 0 ; i < inputDimensions ; i++){ // To find e; the smallest uncovered element
                for (int k = 0 ; k < inputDimensions ; k++){

                    if (inputGrid[i][k] < e && inputReference[i][k] == 0){

                        printf("%i" , inputGrid[i][k]);

                        e = inputGrid[i][k];

                    }

                }
            }

            printf("e is: %i\n" , e);

            for (int i = 0 ; i < inputDimensions ; i++){

                for(int k = 0 ; k < inputDimensions ; k++){

                    if (inputReference[i][k] == 0){

                        inputGrid[i][k] -= e;

                    } else if (inputReference[i][k] == 2){

                        inputGrid[i][k] += e;

                    }

                }

            }

            printf("Augmentation Step:\n");
            outPutAll(inputGrid , inputDimensions);

        }



    }

    printf("End of augmentation:\n");
    outPutAll(inputGrid , inputDimensions);

}

int main(){

    unsigned short int dimen;

    scanf("%hu" , &dimen);

    unsigned short int **testGrid = malloc(dimen * sizeof(unsigned short int*));

    unsigned short int **referenceGrid = malloc(dimen * sizeof(unsigned short int*));

    if (!testGrid){
        return 1;
    } else if (!referenceGrid){
        return 1;
    }

    for ( int i = 0 ; i < dimen ; i++){

        testGrid[i] = malloc(dimen * sizeof(unsigned short int*));
        referenceGrid[i] = malloc(dimen * sizeof(unsigned short int*));

        if (!testGrid[i]){

            return 1;

        } else if (!referenceGrid[i]) {

            return 1;

        }

    }

    for (int i = 0 ; i < dimen ; i++){
        for ( int j = 0 ; j < dimen ; j++){

            unsigned short int tempInput;

            scanf("%hu" , &tempInput);

            testGrid[i][j] = tempInput;
            referenceGrid[i][j] = 0;

        }
    }

    printf("-------\n");

    clock_t start = clock();
    outPutAll(testGrid , dimen);
    clock_t end = clock();

    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("%f\n" , elapsed);

    reduce(testGrid , dimen);
    augment(testGrid , dimen , referenceGrid);

    for ( int i = 0 ; i < dimen ; i++){

        free(testGrid[i]);

    }

    free(testGrid);


    return 0;

}