#include <stdio.h>
#include <stdlib.h> // In the case that I ever need dynamic memory ( for some odd reasons )

struct integerHashTable {

    int maxSize;
    int size;
    int hashTable[1];

};

int hash(int value , int maxSize){
    
    int toReturn = value % maxSize;
    
    return toReturn;
    
}

void output(int table[] , int maxSize){
    
    for (int i = 0 ; i < maxSize ; i++){
        
        printf("%i\n" , table[i]);
        
    }
    
}

void push(int input , int maxSize , int hashTable[]){
    
    int hashedAddress = hash(input , maxSize);
    
    if (hashTable[hashedAddress] == 0){
        hashTable[hashedAddress] = input;
    } else if (hashTable[hashedAddress] != 0){
        
        while (hashTable[hashedAddress] != 0){
            hashedAddress = (hashedAddress + 3) % maxSize;
        }
        
        hashTable[hashedAddress] = input;
        
    }
}

int main() {
    
    int maxSize = 5;
    
    int hashTable[maxSize];
    
    for (int i = 0 ; i < maxSize ; i++){
        hashTable[i] = 0;
    }
    
    int input = 4;
    
    push(input , maxSize , hashTable);
    push(94 , maxSize , hashTable);
    push(55 , maxSize , hashTable);
    
    output(hashTable , maxSize);

    return 0;
}
