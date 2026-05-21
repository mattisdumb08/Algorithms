#include <stdio.h>
#include <stdlib.h>

void push(int input , int stack[] , int *topPointer , int *size , int max){

    if (*topPointer == 0){

        (stack)[0] = input;
        *size += 1;
        *topPointer += 1;

    } else if (*topPointer > 0 && *topPointer < (max)){

        stack[*topPointer + 1] = input;
        *size += 1;
        *topPointer += 1;

    } else if (*topPointer + 1 >= (max)){
        printf("Error: max size of stack reached\n");
    }

}

int pop(int stack[] , int *topPointer){

    if (*topPointer == 0){

        printf("Empty\n");

        return -1;
    }

    int toReturn = stack[*topPointer];

    *topPointer -= 1;

    return toReturn;

}

// Push, pop , peek
int main(){

    int maxSizeOfStack = 4;
    int stack[maxSizeOfStack];
    int size = 0;
    int topPointer = 0;

    for (int i = 0 ; i < maxSizeOfStack ; i++){

        stack[i] = 0; // Initialise to 0 values

    }

    push(23 , stack , &topPointer , &size , maxSizeOfStack);
    push(34 , stack , &topPointer , &size , maxSizeOfStack);
    push(67 , stack , &topPointer , &size , maxSizeOfStack);
    push(76 , stack , &topPointer , &size , maxSizeOfStack);
    push(56 , stack , &topPointer , &size , maxSizeOfStack);
    push(56 , stack , &topPointer , &size , maxSizeOfStack);

    printf("%i" , pop(stack , &topPointer));

    return 0;

}