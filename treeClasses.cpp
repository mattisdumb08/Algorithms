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
        printf("%c\n" , data);
    }

    Node* getLeftPointer(){
        return leftPointer;
    }
    void setLeftPointer(Node *newNodePointer){
        leftPointer = newNodePointer;
    }

    Node* getRightPointer(){
        return rightPointer;
    }
    void setRightPointer(Node *newNodePointer){
        rightPointer = newNodePointer;
    }

    char getData(){
        return data;
    }
};

class Tree{
    private:
    Node *rootNode;
    public:
    Tree(){
        rootNode = nullptr;
    }

    void add(char newCharacter){
        Node newNode(nullptr , newCharacter , nullptr);
        if (rootNode == nullptr){ // If the root node is null / if the tree is empty
            rootNode = &newNode;
            return;
        }

        short int placeFound = false;
        Node *currentNode = rootNode;

        while (placeFound == 0){

            if (currentNode->getLeftPointer() != nullptr){
                if (int(currentNode->getLeftPointer()->getData()) > int(newCharacter)){
                    currentNode = currentNode->getLeftPointer();
                }
            }
            
            if (currentNode->getRightPointer() != nullptr){
                if (int(currentNode->getRightPointer()->getData()) < int(newCharacter)){
                    currentNode = currentNode->getRightPointer();
                }
            }   
        
            if (currentNode->getLeftPointer() == nullptr && currentNode->getRightPointer() == nullptr){
                placeFound = 1;
            }
        }

        if (currentNode->getData() < newCharacter){
            currentNode->setRightPointer(&newNode);
        } else if (currentNode->getData() > newCharacter){
            currentNode->setLeftPointer(&newNode);
        }

        printf("root data: %c\n" , rootNode->getData());

    }

    Node *getRoot(){
        return rootNode;
    }

   
    void preOrder(Node* currentNode){
        printf("%c\n" , (*currentNode).getData());

        // if (currentNode -> getLeftPointer() != nullptr){
        //     preOrder(currentNode->getLeftPointer());
        // }
        // if (currentNode -> getRightPointer() != nullptr){
        //     preOrder(currentNode -> getRightPointer());
        // }
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
    
    printf("Runnig");

    Tree testTree;

    preOrder(&node1);
    printf("-----\n");
    testTree.add('F');
    testTree.add('D');
    testTree.add('B');

    // printf("%c\n" , testTree.getRoot()->getData());

    testTree.preOrder(testTree.getRoot());

    return 0;
}