#include <iostream>

class Node{
    private:
    Node *leftPointer;
    Node *rightPointer;
    char data;
    
    public:

    Node(Node *newLeft , char newData , Node *newRight){
        leftPointer = newLeft;
        rightPointer = newRight;
        data = newData;
    }

    Node* getLeftPointer(){
        return leftPointer;
    }

    Node* getRightPointer(){
        return rightPointer;
    }

    int getData(){
        return data;
    }
};

// Root is F
Node node5(nullptr , 'G' , nullptr);
Node node7(nullptr , 'A' , nullptr);
Node node8(nullptr , 'C' , nullptr);
Node node9(nullptr , 'Z' , nullptr);
Node node4(&node7 , 'B' , &node8);
Node node2(&node4 , 'D' , nullptr);
Node node6(nullptr , 'J' , &node9);
Node node3(&node5 , 'H' , &node6);
Node node1(&node2 , 'F' , &node3);

void preOrder(Node *rootNode){
    std::cout << char(rootNode->getData()) << "\n";
    if (rootNode->getLeftPointer() != nullptr){
        preOrder(rootNode->getLeftPointer());
    }
    if (rootNode->getRightPointer() != nullptr){
        preOrder(rootNode->getRightPointer());
    }
}

int main(){

    preOrder(&node1);

    return 0;
}