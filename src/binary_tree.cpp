#include "binary_tree.h"

// BinaryTree constructor
BinaryTree::BinaryTree(){
    this->height = 0;
    populate();
}

void BinaryTree::populate(){
    std::cout << "Enter the root Node value: ";
    int value;
    std::cin >> value;
    this->root = new Node(value);
    populate(this->root);
}

void BinaryTree::populate(Node* node) {

    // Insert left node
    std::cout << "Do you want to enter left of " << node->value << "? (Y/N): ";
    char left;
    std::cin >> left;
    if (std::tolower(left) == 'y'){
        // Add one to the height
        ++this->height;

        std::cout << "Enter the value of the left of " << node->value << ": ";
        int value;
        std::cin >> value;
        node->left = new Node(value);
        populate(node->left);
    }

    // Insert right node
    std::cout << "Do you want to enter right of " << node->value << "? (Y/N): ";
    char right;
    std::cin >> right;
    if (std::tolower(right) == 'y'){
        std::cout << "Enter the value of the right of " << node->value << ": ";
        int value;
        std::cin >> value;
        node->right = new Node(value);
        populate(node->right);
    }
}

// Display nodes in BT
void BinaryTree::display() {
    display(this->root, "");
}

void BinaryTree::display(Node* node, std::string indent){
    if (node == nullptr) {
        return;
    }
    std::cout << indent << node->value << std::endl;
    display(node->left, indent+"\t");
    display(node->right, indent+"\t");
}


void BinaryTree::pretty_display(){
    pretty_display(this->root, 0);
}

void BinaryTree::pretty_display(Node* node, int level){
    if (node == nullptr) {
        return;
    }
    
    pretty_display(node->right, level+1);

    if (level != 0) {
        for (int i = 0; i < level-1; i++)
        {
            std::cout << "|\t";
        }
        std::cout << "|------>" << node->value << std::endl;
        
    } else {
        std::cout << node->value << std::endl;
    }

    pretty_display(node->left, level+1);

}

// Node constructor
BinaryTree::Node::Node(int value) {
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}
