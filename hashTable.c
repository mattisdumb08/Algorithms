#include <stdio.h>
#include <stdlib.h> // In the case that I ever need dynamic memory ( for some odd reasons )

struct integerHashTable {

    int maxSize;
    int size;
    int* hashTable; // Pointer to an array

};

int hash(int value , int maxSize){
    
    int toReturn = value % maxSize;
    
    return toReturn;
    
}

void outputIntHashTable(struct integerHashTable table){
    
    for (int i = 0 ; i < table.maxSize ; i++){
        
        printf("%i\n" , table.hashTable[i]);
        
    }
    
}

void pushIntHashTable(int input , struct integerHashTable hashTable){
    
    int hashedAddress = hash(input , hashTable.maxSize);
    
    if (hashTable.hashTable[hashedAddress] == 0){
        hashTable.hashTable[hashedAddress] = input;
    } else if (hashTable.hashTable[hashedAddress] != 0){
        
        while (hashTable.hashTable[hashedAddress] != 0){
            hashedAddress = (hashedAddress + 3) % hashTable.maxSize;
        }
        
        hashTable.hashTable[hashedAddress] = input;
        
    }
}

struct integerHashTable newIntegerHashTable(int maxSize){

    struct integerHashTable newTable;

    newTable.size = 0;
    newTable.maxSize = maxSize;
    newTable.hashTable = malloc(sizeof(int)  * maxSize);

    for (int i = 0 ; i < newTable.maxSize ; i++){
        newTable.hashTable[i] = 0;
    }

    return newTable;

}

int main() {
    
    int maxSize = 5;
    
    struct integerHashTable hashTable = newIntegerHashTable(maxSize);
    
    int input = 4;
    
    pushIntHashTable(input , hashTable);
    pushIntHashTable(94  , hashTable);
    pushIntHashTable(55  , hashTable);
    pushIntHashTable(87 , hashTable);
    
    outputIntHashTable(hashTable);

    free(hashTable.hashTable);

    return 0;
}
