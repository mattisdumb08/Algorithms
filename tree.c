#include <stdio.h>
// Array of records approach to trees

struct Node{
    int leftPointer;
    int rightPointer;
    char data;
};

struct Node newNode(int newLeft , char newData , int newRight){
    struct Node newNode;

    newNode.leftPointer = newLeft;
    newNode.data = newData;
    newNode.rightPointer = newRight;

    return newNode;
};

// Root Left Right
void preOrder(struct Node *tree , int rootPointer){
    printf("%c\n" , tree[rootPointer].data);
    if (tree[rootPointer].leftPointer != -1){
        preOrder(tree , tree[rootPointer].leftPointer);
    }

    if (tree[rootPointer].rightPointer != -1){
        preOrder(tree , tree[rootPointer].rightPointer);
    }
    
};

// Left Root Right
void inOrder(struct Node *tree , int rootPointer){
    if (tree[rootPointer].leftPointer != -1){
        inOrder(tree , tree[rootPointer].leftPointer);
    }

    printf("%c\n" , tree[rootPointer].data);

    if (tree[rootPointer].rightPointer != -1){
        inOrder(tree , tree[rootPointer].rightPointer);
    }
    
};

// Left Right Root
void postOrder(struct Node *tree , int rootPointer){
    if (tree[rootPointer].leftPointer != -1){
        postOrder(tree , tree[rootPointer].leftPointer);
    }
    if (tree[rootPointer].rightPointer != -1){
        postOrder(tree , tree[rootPointer].rightPointer);
    }

    printf("%c\n" , tree[rootPointer].data);
};

int main(){

    struct Node tree[7] = {
        newNode(1 , 'A' , 2),
        newNode(3 , 'B' , 4),
        newNode(5 , 'C' , -1),
        newNode(-1 , 'D' , 6),
        newNode(-1 , 'E' , -1),
        newNode(-1 , 'F' , -1),
        newNode(-1 , 'G' , -1)
    };

    printf("%c\n" , tree[0].data);

    preOrder(tree , 0);
    printf("-----\n");
    inOrder(tree , 0);
    printf("-----\n");
    postOrder(tree , 0);

    return 0;
}