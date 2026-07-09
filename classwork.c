#include <stdio.h>

struct Node {
    int leftPointer;
    char data;
    int rightPointer;
};

struct Node Node(int newLeft , int newData , int newRight){
    struct Node newNode;

    newNode.leftPointer = newLeft;
    newNode.data = newData;
    newNode.rightPointer = newRight;

    return newNode;
};

void preOrder(struct Node *tree , int rootPointer){
    printf("%c\n" , tree[rootPointer].data);
    if (tree[rootPointer].leftPointer != -1){
        preOrder(tree , tree[rootPointer].leftPointer);
    }
    if (tree[rootPointer].rightPointer != -1){
        preOrder(tree , tree[rootPointer].rightPointer);
    }
};

void inOrder(struct Node *tree , int rootPointer){
    if (tree[rootPointer].leftPointer != -1){
        inOrder(tree , tree[rootPointer].leftPointer);
    }
    printf("%c\n" , tree[rootPointer].data);
    if (tree[rootPointer].rightPointer != -1){
        inOrder(tree , tree[rootPointer].rightPointer);
    }
};

void postOrder(struct Node *tree , int rootPointer){
    if (tree[rootPointer].leftPointer != -1){
        postOrder(tree , tree[rootPointer].leftPointer);
    }
    if (tree[rootPointer].rightPointer != -1){
        postOrder(tree , tree[rootPointer].rightPointer);
    }
    printf("%c\n" , tree[rootPointer].data);
}

int main(){

    
    struct Node tree[9] = {
        Node(-1 , 'A' , -1),
        Node(0 , 'B' , 2),
        Node(-1, 'C' , -1),
        Node(1 , 'D' , -1),
        Node(3 , 'F' , 6),
        Node(-1 , 'G' , -1),
        Node(5 , 'H' , 7),
        Node(-1 , 'J' , 8),
        Node(-1 , 'Z' , -1)
    };

    preOrder(tree , 4);
    printf("----\n");
    inOrder(tree , 4);
    printf("----\n");
    postOrder(tree , 4);

    return 0;
}