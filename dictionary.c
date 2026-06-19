#include <stdio.h>
#include <stdlib.h>

struct IntDictionary{
    int *array;
    int maxSize;
    int size;

};

struct IntKeyValuePair{
    int value;
    char *key;

};

int lengthOfString(char *thisString){

    int length = 0;

    while (thisString[length] != '\0'){

        length += 1;

    }

    return length;

}

int sizeOfStringASCII(char *thisString){

    int totalSize = 0;
    int current = 0;

    while (thisString[current] != '\0'){

        totalSize += (int)thisString[current];
        current += 1;

    }

    return totalSize;

}

int hash(int value , int diviser){

    int toReturn = value % diviser;

    return toReturn;

}

struct IntDictionary *IntDictionaryNew(int maxSize){

    struct IntDictionary *temp = malloc(sizeof(struct IntDictionary));

    temp->array = calloc(maxSize , sizeof(struct IntDictionary));
    temp->size = 0;
    temp->maxSize = maxSize;

    return temp;

}

void IntDictionaryAdd(char *key , int newValue , struct IntDictionary *thisDictionary){

    if (thisDictionary->size >= thisDictionary->maxSize){

        printf("Error: The dictionary is full");

        return;

    }

    int sizeOfKey = lengthOfString(key);
    int asciiValue = sizeOfStringASCII(key);

    printf("%s\n" , key);
    printf("%i\n" , sizeOfKey);
    printf("%i\n" , asciiValue); 

}

// at , add , remove
int main(){

    struct IntDictionary *testDictionary = IntDictionaryNew(5);

    IntDictionaryAdd("hello" , 1 , testDictionary);

    return 0;

}