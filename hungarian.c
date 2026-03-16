#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Use this to test
//|10| |5| |7| |12|
//|9| |6| |9| |10|
//|7| |12| |10| |8|
//|9| |5| |9| |8|
// Time:
// 0.000215 seconds
// Note: probably because of the compiler and its optimisations.

// This works; it retries augmentation and when sum of lines are equal to the n dimensions then it will not perform the subtractions.

// The algorithm will arbitrarily place a line horizontally in the case that the number of uncovered zeros in a row are equal tot he number of
// uncovered zeros in a column.

// Currently, the program requires further extension to perform decision making on an nXn matrix, maximising allocations and computing
// nXm matrices.

// It is probably really inefficient. It's probably <O(n^3)

void outputAll(unsigned short int **inGrid , int inDimensions){ // Output the whole grid with a break at the top to differentiate

    printf("-------\n");

    for (int i = 0 ; i < inDimensions ; i++){

        for (int k = 0 ; k < inDimensions ; k++){

            printf("|%i| " , inGrid[i][k]);

        }

        printf("\n");

    }

}

void reduce(unsigned short int **inputGrid , int inputDimensions){ // Reduce the column and the rows

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
    outputAll(inputGrid , inputDimensions);

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
    outputAll(inputGrid , inputDimensions);

}

void augment(unsigned short int **inputGrid , int inputDimensions , unsigned short int **inputReference){ // Placing lines to cover
// Any uncovered 0s and subtracting all uncovered by the smallest uncovered element.

    int numberOfLines = 0;

    bool isOptimal = false;
    bool beenAugmented = false;

    int numberOfZerosRows;

    int numberOfZerosColumns;

    while (isOptimal == false){

        numberOfLines = 0;

        int numberOfZerosRows;

        int numberOfZerosColumns;

        for (int a = 0 ; a < inputDimensions ; a++){ // Rest reference grid to 0

            for (int b = 0 ; b < inputDimensions ; b++){

                inputReference[a][b] = 0;

            }

        }

        // for (int i = 0 ; i < inputDimensions ; i++){

        //     numberOfZerosRows = 0; // Reset the number of zeros in each next diagonal
        //     numberOfZerosColumns = 0;

        //     for (int k = 0 ; k < inputDimensions ; k++){

        //         if (inputGrid[i][k] == 0){

        //             numberOfZerosRows += 1;

        //         } else if (inputGrid[k][i] == 0){

        //             numberOfZerosColumns += 1;

        //         }

        //     }

        //     if (numberOfZerosColumns > numberOfZerosRows){

        //         for (int j = 0 ; j < inputDimensions ; j ++){

        //             inputReference[j][i] += 1;

        //         }

        //         numberOfLines += 1;

        //     } else if (numberOfZerosColumns == numberOfZerosRows){

        //         for (int j = 0 ; j < inputDimensions ; j++){

        //             inputReference[i][j] += 1;

        //         }

        //         numberOfLines += 1;

        //     }


        // }

        for (int i = 0 ; i < inputDimensions ; i++){ // Go through the whole grid and referenceGrid to check if there are any remaining 0s that are not covered

            for (int k = 0 ; k < inputDimensions ; k++){
                
                unsigned short int tempRowTotal = 0;
                unsigned short int tempColumnTotal = 0;

                if (inputGrid[i][k] == 0 && inputReference[i][k] == 0){

                    for(int a = 0 ; a < inputDimensions ; a++){

                        if (inputGrid[i][a] == 0){

                            tempRowTotal += 1;

                        } 
                        
                        if (inputGrid[a][k] == 0){

                            tempColumnTotal += 1;

                        }
                    
                    }

                    // printf("%i " , tempRowTotal);
                    // printf("%i" , tempColumnTotal);

                    if (tempRowTotal > tempColumnTotal || tempRowTotal == tempColumnTotal){

                        for (int a = 0 ; a < inputDimensions ; a++){

                            inputReference[i][a] += 1;

                        }

                        numberOfLines += 1;

                    } else if (tempColumnTotal > tempRowTotal){

                        for (int a = 0 ; a < inputDimensions ; a++){

                            inputReference[a][k] += 1;

                        }

                        numberOfLines += 1;

                    }

                    outputAll(inputReference , inputDimensions);

                }
                
                // Depending on which total is larger create a line in that direction


            }

        }

        printf("%i" , numberOfLines);

        if (numberOfLines == inputDimensions){

            isOptimal = true;

        } else if (numberOfLines < inputDimensions){

            int e;

            for ( int a = 0 ; a < inputDimensions ; a++){ // To find a starting value for e in case smallest is larger than default value given.

                for (int b = 0 ; b < inputDimensions ; b++){

                    if (inputReference[a][b] == 0){

                        e = inputGrid[a][b];

                    }

                }

            }

            for (int i = 0 ; i < inputDimensions ; i++){ // To find e; the smallest uncovered element
                for (int k = 0 ; k < inputDimensions ; k++){

                    if (inputGrid[i][k] < e && inputReference[i][k] == 0){

                        e = inputGrid[i][k];

                    }

                }
            }

            printf("e is: %i\n" , e);

            for (int i = 0 ; i < inputDimensions ; i++){

                for(int k = 0 ; k < inputDimensions ; k++){

                    if (inputReference[i][k] == 0){

                        inputGrid[i][k] -= e;

                    }
                    
                    else if (inputReference[i][k] == 2){

                        inputGrid[i][k] += e;

                    }

                }

            }
        }

        printf("Augmentation Step:\n"); // Output the end of augmenting
        outputAll(inputGrid , inputDimensions);

        outputAll(inputReference  , inputDimensions);

    }

    if (beenAugmented == true){
        printf("End of augmentation:\n");
        outputAll(inputGrid , inputDimensions);
    } else {

        printf("End result (no augmentation required):\n");
        outputAll(inputGrid , inputDimensions);

    }

}

int main(){

    unsigned short int dimen;

    printf("Enter n value for dimensions (nXn):");    
    scanf("%hu" , &dimen);

    unsigned short int **testGrid = malloc(dimen * sizeof(unsigned short int*));
    unsigned short int **copyGrid = malloc(dimen * sizeof(unsigned short int*));
    unsigned short int **referenceGrid = malloc(dimen * sizeof(unsigned short int*));

    if (!testGrid){ // If memory cannot be assigned to any of those pointers
        return 1;
    } else if (!referenceGrid){
        return 1;
    } else if (!copyGrid){
        return 1;
    }

    for (int i = 0 ; i < dimen ; i++){

        testGrid[i] = malloc(dimen * sizeof(unsigned short int*));
        referenceGrid[i] = malloc(dimen * sizeof(unsigned short int*));
        copyGrid[i] = malloc(dimen * sizeof(unsigned short int *));

        if (!testGrid[i]){
            return 1;
        } else if (!referenceGrid[i]) {
            return 1;
        } else if (!copyGrid[i]){
            return 1;
        }

    }

    for (int i = 0 ; i < dimen ; i++){

        printf("current row: %i\n" , i + 1);

        for ( int j = 0 ; j < dimen ; j++){

            unsigned short int tempInput;

            scanf("%hu" , &tempInput);

            testGrid[i][j] = tempInput;
            copyGrid[i][j] = tempInput;
            referenceGrid[i][j] = 0;

        }
    }

    printf("-------\n");

    outputAll(testGrid , dimen);

    clock_t start = clock();
    reduce(testGrid , dimen);
    augment(testGrid , dimen , referenceGrid);
    clock_t end = clock();

    printf("Original cost matrix:\n");
    outputAll(copyGrid , dimen);

    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("%f" , elapsed);

    for ( int i = 0 ; i < dimen ; i++){

        free(testGrid[i]);
        free(referenceGrid[i]);
        free(copyGrid[i]);

    }

    free(testGrid);
    free(referenceGrid);
    free(copyGrid);

    int windowHold;

    scanf("%i" , &windowHold);

    return 0;

}