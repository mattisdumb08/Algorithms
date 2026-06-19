#include <stdio.h>
#include <stdlib.h>

struct IntQueue{
    int *array;
    int frontPointer;
    int rearPointer;
    int maxSize;
    int size;
};

struct IntQueue * newIntQueue(int maxSize){

    struct IntQueue * temp = malloc(sizeof(struct IntQueue));

    temp->array = calloc(maxSize , sizeof(int)); // Initialises all values of the array to 0
    temp->frontPointer = -1; // Points to the next value to be dequeued
    temp->rearPointer = -1; // Will point to the next free space
    temp->size = 0;
    temp->maxSize = maxSize;

    return temp;

}

void intQueueFree(struct IntQueue *thisQueue){ // Release memory taken by the struct and its members

    free(thisQueue->array);
    free(thisQueue);

}

void intQueueEnqueue(int input , struct IntQueue *thisQueue){

    if (thisQueue->rearPointer == -1){ // When the queue is uninitialised

        printf("Uninit\n");

        thisQueue->array[0] = input;

        thisQueue->rearPointer = 1;
        thisQueue->frontPointer = 0;
        thisQueue->size += 1;

        return;

    }

    if (thisQueue->size == 0 && thisQueue->rearPointer != -1){ // if the queue is empty

        printf("Empty\n");

        thisQueue->array[thisQueue->rearPointer] = input;

        thisQueue->frontPointer = thisQueue->rearPointer;
        thisQueue->rearPointer = (thisQueue->rearPointer + 1) % thisQueue->maxSize;
        thisQueue->size += 1;

        return;

    }

    if (thisQueue->size >= thisQueue->maxSize){

        printf("Full\n");

        printf("Error: the queue is full\n");

        return;
    }

    printf("Normal\n");

    thisQueue->array[thisQueue->rearPointer] = input;
    thisQueue->rearPointer = (thisQueue->rearPointer + 1) % thisQueue->maxSize;
    thisQueue->size += 1;

}

int intQueueDequeue(struct IntQueue *thisQueue){

    if (thisQueue->frontPointer == -1){
        printf("Error: the queue is uninitialised; returning -1\n");
        return -1;
    }
    
    if (thisQueue->size == 0){

        printf("Error: the queue is empty; returning -1\n");
        return -1;

    }

    int toReturn = thisQueue->array[thisQueue->frontPointer];
    thisQueue->array[thisQueue->frontPointer] = -1;

    thisQueue->frontPointer = (thisQueue->frontPointer + 1) % thisQueue -> maxSize;
    thisQueue->size -= 1;

    return toReturn;

}

// Enqueue , Dequeue
int main(){

    struct IntQueue *testQueue = newIntQueue(5);

    for (int i = 0 ; i < 5 ; i++){
        printf("%i\n" , testQueue->array[i]);
    }

    intQueueEnqueue(5 , testQueue);
    intQueueEnqueue(10 , testQueue);
    intQueueEnqueue(15 , testQueue);
    intQueueEnqueue(20 , testQueue);
    intQueueEnqueue(25 , testQueue);
    intQueueEnqueue(30 , testQueue);

    printf("-----\n");

    printf("%i\n" , testQueue->frontPointer);
    printf("%i\n" , testQueue->rearPointer);

    printf("-----\n");

    for (int i = 0 ; i < 5 ; i++){
        printf("%i\n" , testQueue->array[i]);
    }

    printf("-----\n");

    printf("%i\n" , intQueueDequeue(testQueue));
    printf("%i\n" , intQueueDequeue(testQueue));
    printf("%i\n" , intQueueDequeue(testQueue));
    printf("%i\n" , intQueueDequeue(testQueue));
    printf("%i\n" , intQueueDequeue(testQueue));
    printf("%i\n" , intQueueDequeue(testQueue));


    intQueueFree(testQueue);

    return 0;

}