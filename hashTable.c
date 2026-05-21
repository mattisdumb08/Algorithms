#include <stdio.h>
#include <stdlib.h> // In the case that I ever need dynamic memory

struct integerHashTable {

    int maxSize; // Max size of the hashTable
    int size; // Current size / number of elements in the hash Table
    int* hashTable; // Pointer to an array

};

// Calculates the address from the input and the maximum size
int hash(int value , int maxSize){
    
    int toReturn = value % maxSize;
    
    return toReturn;
    
}

// Outputs all the elements of the hashTable ( not standard but just for testing )
void outputIntHashTable(struct integerHashTable *table){
    
    for (int i = 0 ; i < table->maxSize ; i++){
        
        printf("%i\n" , table->hashTable[i]);
        
    }
    
}


// Input elements into the hashTable ( doesn't really work as it does normally )
// No safeguards so memory corruption if inputs exceed the maximum number of elements
void pushIntHashTable(int input , struct integerHashTable *hashTable){
    
    int hashedAddress = hash(input , hashTable->maxSize);
    
    if (hashTable->size >= hashTable->maxSize){
        printf("Error: Max capacity of the hash table has been reached (%i)\n" , input);
        return;
    }

    if (hashTable->hashTable[hashedAddress] == 0){
        hashTable->hashTable[hashedAddress] = input;
        hashTable->size = hashTable->size + 1;
    } else if (hashTable->hashTable[hashedAddress] != 0){

        unsigned short int iterations = 0;

        int previousAddress = hashedAddress;

        short int addressFound = 0;
        
        while (hashTable->hashTable[hashedAddress] != 0){
            hashedAddress = (hashedAddress + 3) % hashTable->maxSize;

            if (hashedAddress < previousAddress){
                iterations += 1;
            }

            if (iterations >= 4){
                break;
            }

            previousAddress = hashedAddress;
            addressFound = 1;
        }
        
        if (addressFound == 1){
            hashTable->hashTable[hashedAddress] = input;
            hashTable->size = hashTable->size + 1;
        }
        
    }

    return;
}

// Initialiser for the IntegerHashTable struct
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
    
    pushIntHashTable(input , &hashTable);
    pushIntHashTable(94  , &hashTable);
    pushIntHashTable(55  , &hashTable);
    pushIntHashTable(87 , &hashTable);
    pushIntHashTable(634 , &hashTable);
    pushIntHashTable(999 , &hashTable);

    outputIntHashTable(&hashTable);

    // Frees the memory of the malloc in the struct
    free(hashTable.hashTable);

    return 0;
}
