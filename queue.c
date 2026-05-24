#include <stdio.h>
#include <stdlib.h>

struct IntQueue{
    int *array;
    int frontPointer;
    int rearPointer;
    int maxSize;
};

struct IntQueue * newIntQueue(int maxSize){

    struct IntQueue * temp = malloc(sizeof(struct IntQueue));

    temp->array = calloc(maxSize , sizeof(int)); // Initialises all values of the array to 0

    temp->frontPointer = -1;
    temp->rearPointer = -1;

    return temp;

}

int main(){

    struct IntQueue *testQueue = newIntQueue(5);

    for (int i = 0 ; i < 5 ; i++){
        printf("%i\n" , testQueue->array[i]);
    }

    return 0;

}