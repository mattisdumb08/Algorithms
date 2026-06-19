#include <stdio.h>
#include <stdlib.h>

struct IntNode{

  int value;
  struct IntNode *nextPointer;  

};

struct IntNode* newIntNode(int newValue){

    struct IntNode *newNode = malloc(sizeof(struct IntNode));
    newNode->value = newValue;
    newNode->nextPointer = NULL;
    
    return newNode;

}

struct IntLinkedList{

    struct IntNode *headPointer;

};

struct IntLinkedList* newIntLinkedList(){

    struct IntLinkedList *tempLinkedList = malloc(sizeof(struct IntLinkedList));
    tempLinkedList->headPointer = NULL;

    return tempLinkedList;

};

void intLinkedListAppend(int newValue , struct IntLinkedList *theList){

    struct IntNode *newNode = newIntNode(newValue);

    if (theList->headPointer == NULL){
        theList->headPointer = newNode;
    } else if (theList->headPointer != NULL){ // If the linked list is not empty
        struct IntNode *current = theList->headPointer;

        while (current->nextPointer != NULL){
            current = current->nextPointer;
        }

        current->nextPointer = newNode;

    }

}

void intLinkedListRemove(int toRemove , struct IntLinkedList *theList){

    if (theList->headPointer == NULL){

        printf("Error: The integer linked list is empty");

    } else if (theList->headPointer != NULL){

        struct IntNode *current = theList->headPointer;
        struct IntNode *previous = current;

        if (theList->headPointer->nextPointer == NULL && theList->headPointer->value == toRemove){

            free(theList->headPointer);
            theList->headPointer = NULL;
            return;

        } else if (theList->headPointer->nextPointer != NULL && theList->headPointer->value == toRemove){

            struct IntNode *next = theList->headPointer->nextPointer;
            free(theList->headPointer);
            theList->headPointer = next;
            return;

        }

        while (current != NULL){

            if (current->value == toRemove){

                previous->nextPointer = current->nextPointer;

                free(current);
                break;

            }

            previous = current;
            current = current->nextPointer;

        }

    }

}

void intLinkedListTraverse(struct IntLinkedList *theList){
    struct IntNode *current = theList->headPointer;

    while (current != NULL){

        printf("%i\n" , current->value);
        current = current->nextPointer;

    }

}

void intLinkedListFree(struct IntLinkedList *theList){

    struct IntNode *current = theList->headPointer;

    while (current != NULL){

        struct IntNode *toFree = current;
        current = current->nextPointer;

        free(toFree);

    }

    free(theList);

}


int main(){

    struct IntLinkedList *linkedList = newIntLinkedList();
    intLinkedListAppend(23 , linkedList);
    intLinkedListAppend(67 , linkedList);
    intLinkedListAppend(78 , linkedList);
    intLinkedListRemove(23 , linkedList);
    intLinkedListTraverse(linkedList);

    intLinkedListFree(linkedList);

    return 0;

}
