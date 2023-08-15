#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <cctype>

class BinaryTree{
public:
    // Constructor
    BinaryTree();

    class Node{
    public:
        int value;
        Node* left;
        Node* right;
        Node(int value);
        // Overload << operator
        friend std::ostream& operator <<(std::ostream& os, const Node& node);
    };

    // Insert elements
    void populate();
    void populate(Node* node);
    void display();
    void display(Node* node, std::string indent);
    void pretty_display();
    void pretty_display(Node* node, int level);

private:
    Node* root;
    int height;
};


#endif //BINARY_TREE_H