#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

class BST {
public:
    class Node {
        int value;
        int height;
        Node* left;
        Node* right;

    public:
        Node(int value);
        int getValue();
        int getHeight();
        void setHeight(int height);
        Node* getLeft();
        void setLeft(Node* node);
        Node* getRight();
        void setRight(Node* node);
    };

    // Constructor
    BST();
    int getHeight(Node* node);
    bool isEmpty();
    bool balanced();
    bool balanced(Node* node);
    void display();
    void display(Node* node, std::string details);
    void insert(int value);
    Node* insert(int value, Node* node);
    void populate(std::vector<int>& nums);
    void populateSorted(std::vector<int>& nums);
    void populateSorted(std::vector<int>& nums, int start, int end);
    
    // Traversal
    void preOrder();
    void preOrder(Node* node);
    void inOrder();
    void inOrder(Node* node);
    void postOrder();
    void postOrder(Node* node);

private:
    Node* root;


};



#endif //BST_H