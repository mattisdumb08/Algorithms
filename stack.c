#include <stdio.h>
#include <stdlib.h>

struct IntegerStack{

    int *stack;
    int *stateTracker;
    int topPointer;
    int size;
    int maxSize;

};

void push(int input , int stack[] , int *topPointer , int *size , int max){

    if (*topPointer == -1){

        (stack)[0] = input;
        *size += 1;
        *topPointer = 0;
        printf("Pushed %i\n" , input);

    } else if (*size > 0 && *size < (max)){

        stack[*topPointer + 1] = input;
        *size += 1;
        *topPointer += 1;
        printf("Pushed %i\n" , input);

    } else if (*size >= max){
        printf("Error: max size of stack reached\n");
    }

}

int pop(int stack[] , int *topPointer , int *size){

    if (*topPointer == -1){

        printf("Empty\n");

        return -1;
    }

    int toReturn = stack[*topPointer];

    *topPointer -= 1;
    *size -= 1;

    return toReturn;

}

int peek(int stack[] , int *topPointer , int *size){

    if (*topPointer == -1){

        printf("Error: empty stack\n");

        return -1;
    }

    return stack[*topPointer];

}

void intStackPush(int input , struct IntegerStack *thisStack){
     
     // Empty Stack
    if (thisStack->topPointer == -1){
        thisStack->topPointer = 0;
        thisStack->stack[thisStack->topPointer] = input;
        thisStack->stateTracker[thisStack->topPointer] = 1;
    } else if (thisStack->topPointer != -1 && thisStack->topPointer < thisStack->maxSize - 1){

        thisStack->topPointer += 1;
        thisStack->stack[thisStack->topPointer] = input;
        thisStack->stateTracker[thisStack->topPointer] = 1;
    } else if (thisStack->topPointer == thisStack->maxSize - 1){

        printf("Error: The stack is full.\n");

    }

}

int intStackPop(struct IntegerStack *thisStack){

    if (thisStack->topPointer == -1){

        printf("Error: The stack is empty; returning -1");

        return -1;

    } else if (thisStack->topPointer > -1){

        int toReturn = thisStack->stack[thisStack->topPointer];

        thisStack->stateTracker[thisStack->topPointer] = -1;
        thisStack->stack[thisStack->topPointer] = 0;

        thisStack->topPointer -= 1;

        return toReturn;

    }

}

int intStackPeek(struct IntegerStack *thisStack){

    if (thisStack->topPointer == -1){
        printf("Error: The stack is empty; returning -1");
        return -1;
    } else if (thisStack->topPointer > -1){
        return thisStack->stack[thisStack->topPointer];
    }

}

struct IntegerStack newIntegerStack(int newMaxSize){
    struct IntegerStack temp;
    temp.maxSize = newMaxSize;
    temp.size = 0;
    temp.stack =  malloc(sizeof(int) * newMaxSize);
    // 1 - occupied , 0 - empty , - -1 deleted
    temp.stateTracker = malloc(sizeof(int) * newMaxSize);
    temp.topPointer = -1;

    for (int i = 0 ; i < newMaxSize ; i++){
        temp.stateTracker[i] = 0;
        temp.stack[i] = 0;
    }

    return temp;
    
}

void freeIntStack(struct IntegerStack *thisStack){

    free(thisStack->stack);
    free(thisStack->stateTracker);

}

// Push, pop , peek
int main(){

    int maxSizeOfStack = 4;
    int stack[maxSizeOfStack];
    int size = 0;
    int topPointer = -1;

    for (int i = 0 ; i < maxSizeOfStack ; i++){

        stack[i] = -1; // Initialise to 0 values

    }

    struct IntegerStack testStack = newIntegerStack(4);

    intStackPush(19 , &testStack);
    intStackPush(20 , &testStack);
    intStackPush(21 , &testStack);
    intStackPush(22 , &testStack);
    intStackPush(23 , &testStack);

    printf("%i\n" , intStackPop(&testStack));
    printf("%i\n" , intStackPeek(&testStack));
    printf("%i\n" , intStackPeek(&testStack));

    // default stack implementation without structs
    // push(23 , stack , &topPointer , &size , maxSizeOfStack);
    // push(34 , stack , &topPointer , &size , maxSizeOfStack);
    // push(67 , stack , &topPointer , &size , maxSizeOfStack);
    // push(76 , stack , &topPointer , &size , maxSizeOfStack);
    // push(56 , stack , &topPointer , &size , maxSizeOfStack);
    // push(56 , stack , &topPointer , &size , maxSizeOfStack);

    // printf("%i\n" , pop(stack , &topPointer , &size));
    // printf("%i\n" , pop(stack , &topPointer , &size));
    // printf("%i\n" , pop(stack , &topPointer , &size));
    // printf("%i\n" , pop(stack , &topPointer , &size));

    freeIntStack(&testStack);

    printf("0\n");

    return 0;

}