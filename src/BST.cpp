#include "BST.h"

// BST
BST::BST() {
    this->root = nullptr;
}

int BST::getHeight(Node* node) {
    if (node == nullptr) {
        return -1;
    }
    return node->getHeight();
}

bool BST::isEmpty() {
    return root == nullptr;
}

bool BST::balanced() {
    return balanced(root);
}

bool BST::balanced(Node* node) {
    if (node == nullptr) {
        return true;
    }
    return abs(getHeight(node->getLeft()) - getHeight(node->getRight())) <= 1 
    && balanced(node->getLeft()) && balanced(node->getRight());
}

void BST::display(){
    display(root, "Root node: ");
}

void BST::display(Node* node, std::string details){
    if (node == nullptr) {
        return;
    }
    std::cout << details << node->getValue() << ", \th=" << getHeight(node) << std::endl;
    display(node->getLeft(), "Left child of " + std::to_string(node->getValue()) + ": ");
    display(node->getRight(), "Right child of " + std::to_string(node->getValue()) + ": ");
}

void BST::insert(int value) {
    root = insert(value, root);
}

BST::Node* BST::insert(int value, Node* node){
    if (node == nullptr) {
        node = new Node(value);
        return node;
    }

    if (value < node->getValue()) {
        Node* node_left = insert(value, node->getLeft());
        node->setLeft(node_left);
    } 

    if (value > node->getValue()) {
        Node* node_right = insert(value, node->getRight());
        node->setRight(node_right);
    }

    int new_height = std::max(getHeight(node->getLeft()), getHeight(node->getRight())) + 1;
    node->setHeight(new_height);
    return node;
}

void BST::populate(std::vector<int>& nums) {
    for (size_t i = 0; i < nums.size(); i++)
    {
        insert(nums[i]);
    }
}

void BST::populateSorted(std::vector<int>& nums) {
    populateSorted(nums, 0, nums.size()); 
}

void BST::populateSorted(std::vector<int>& nums, int start, int end){
    if (start >= end) {
        return;
    }
    int midd = (start+end)/2;
    insert(nums[midd]);
    // LHS & RHS
    populateSorted(nums, start, midd);
    populateSorted(nums, midd+1, end);

}


// Traversals
void BST::preOrder(){
    preOrder(root);
    std::cout << "end" << std::endl;
}

void BST::preOrder(Node* node) {
    if (node == nullptr){
        return;
    }

    std::cout << node->getValue() << "->";
    preOrder(node->getLeft());
    preOrder(node->getRight());
}

void BST::inOrder(){
    inOrder(root);
    std::cout << "end" << std::endl;
}

void BST::inOrder(Node* node){
    if (node == nullptr){
        return;
    }

    inOrder(node->getLeft());
    std::cout << node->getValue() << "->";
    inOrder(node->getRight());
}

void BST::postOrder(){
    postOrder(root);
    std::cout << "end" << std::endl;
}

void BST::postOrder(Node* node){
    if (node == nullptr){
        return;
    }

    postOrder(node->getLeft());
    postOrder(node->getRight());
    std::cout << node->getValue() << "->";
}


// Node
BST::Node::Node(int value) {
    this->value = value;
    this->height = 0;
    this->left = nullptr;
    this->right = nullptr;
}

int BST::Node::getValue() {
    return value;
}

int BST::Node::getHeight() {
    return height;
}

void BST::Node::setHeight(int height) {
    this->height = height;
}

BST::Node* BST::Node::getLeft() {
    return left;
}

void BST::Node::setLeft(Node* node) {
    left = node;
}

BST::Node* BST::Node::getRight() {
    return right;
}

void BST::Node::setRight(Node* node) {
    right = node;
}