#include <stdio.h>
#include <stdlib.h>

struct IntNode{

  int value;
  struct IntNode *nextPointer;  

};

struct IntNode newIntNode(int newValue){

    struct IntNode newNode;
    newNode.value = newValue;
    newNode.nextPointer = NULL;
    
    return newNode;

}

struct IntLinkedList{

    struct IntNode *headPointer;

};

struct IntLinkedList newIntLinkedList(){

    struct IntLinkedList tempLinkedList;
    tempLinkedList.headPointer = NULL;

    return tempLinkedList;

}

void intLinkedListAppend(int newValue , struct IntLinkedList *theList){

    struct IntNode newNode = newIntNode(newValue);

    if (theList->headPointer == NULL){
        printf("Path 0\n");
        theList->headPointer = &newNode;
    } else if (theList->headPointer != NULL){ // If the linked list is not empty
        struct IntNode *current = theList->headPointer;

        printf("Path 1\n");

        while (current->nextPointer != NULL){
            current = current->nextPointer;
        }

        current->nextPointer = &newNode;

    }

}

void intLinkedListTraverse(struct IntLinkedList *theList){
    struct IntNode *current = theList->headPointer;

    while (current != NULL){

        printf("%i\n" , current->value);
        current = current->nextPointer;

    }

}


int main(){

    struct IntLinkedList linkedList = newIntLinkedList();
    intLinkedListAppend(23 , &linkedList);
    intLinkedListAppend(67 , &linkedList);
    intLinkedListAppend(78 , &linkedList);
    intLinkedListTraverse(&linkedList);

    return 0;

}
