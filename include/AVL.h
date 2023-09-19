#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

class AVL{
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
    AVL();
    int getHeight() const;
    int getHeight(Node* node);
    bool isEmpty();
    bool balanced();
    void display();
    void insert(int value);
    void populate(std::vector<int>& nums);
    void populateSorted(std::vector<int>& nums);
    
    // Traversal
    void preOrder();
    void inOrder();
    void postOrder();

    // Reload << operator
    friend std::ostream& operator<<(std::ostream& os, const AVL& avl);


private:
    bool balanced(Node* node);
    void display(Node* node, std::string details);
    Node* insert(int value, Node* node);
    void populateSorted(std::vector<int>& nums, int start, int end);

    void preOrder(Node* node);
    void inOrder(Node* node);
    void postOrder(Node* node);
    
    // Autobalancing the tree
    Node* rotate(Node* node);
    Node* rightRotate(Node* node);
    Node* leftRotate(Node* node);

    // Print the tree
    void add_column(std::vector<std::string>& columns, Node* node, int height) const;
    int count_digits(int n) const;

    Node* root;

};



#endif //AVL_H