#include "AVL.h"

// AVL
AVL::AVL() {
    this->root = nullptr;
}

int AVL::getHeight() const{
    if (this->root == nullptr) {
        return -1;
    }
    return root->getHeight();
}

int AVL::getHeight(Node* node) {
    if (node == nullptr) {
        return -1;
    }
    return node->getHeight();
}

bool AVL::isEmpty() {
    return root == nullptr;
}

bool AVL::balanced() {
    return balanced(root);
}

bool AVL::balanced(Node* node) {
    if (node == nullptr) {
        return true;
    }
    return abs(getHeight(node->getLeft()) - getHeight(node->getRight())) <= 1 
    && balanced(node->getLeft()) && balanced(node->getRight());
}

void AVL::display(){
    display(root, "Root node: ");
}

void AVL::display(Node* node, std::string details){
    if (node == nullptr) {
        return;
    }
    std::cout << details << node->getValue() << ", \th=" << getHeight(node) << std::endl;
    display(node->getLeft(), "Left child of " + std::to_string(node->getValue()) + ": ");
    display(node->getRight(), "Right child of " + std::to_string(node->getValue()) + ": ");
}

void AVL::insert(int value) {
    root = insert(value, root);
}

AVL::Node* AVL::insert(int value, Node* node){
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

    int new_height = std::max(getHeight(node->getLeft()), getHeight(node->getRight()))+1;
    node->setHeight(new_height);

    // Balancing the tree when inserting the node
    return rotate(node);
}

void AVL::populate(std::vector<int>& nums) {
    for (size_t i = 0; i < nums.size(); i++)
    {
        insert(nums[i]);
    }
}

void AVL::populateSorted(std::vector<int>& nums) {
    populateSorted(nums, 0, nums.size()); 
}

void AVL::populateSorted(std::vector<int>& nums, int start, int end){
    if (start >= end) {
        return;
    }
    int mid = (start+end)/2;
    insert(nums[mid]);
    // LHS & RHS
    populateSorted(nums, start, mid);
    populateSorted(nums, mid+1, end);

}


// Traversals
void AVL::preOrder(){
    preOrder(root);
    std::cout << "end" << std::endl;
}

void AVL::preOrder(Node* node) {
    if (node == nullptr){
        return;
    }

    std::cout << node->getValue() << "->";
    preOrder(node->getLeft());
    preOrder(node->getRight());
}

void AVL::inOrder(){
    inOrder(root);
    std::cout << "end" << std::endl;
}

void AVL::inOrder(Node* node){
    if (node == nullptr){
        return;
    }

    inOrder(node->getLeft());
    std::cout << node->getValue() << "->";
    inOrder(node->getRight());
}

void AVL::postOrder(){
    postOrder(root);
    std::cout << "end" << std::endl;
}

void AVL::postOrder(Node* node){
    if (node == nullptr){
        return;
    }

    postOrder(node->getLeft());
    postOrder(node->getRight());
    std::cout << node->getValue() << "->";
}


// Balancing
AVL::Node* AVL::rotate(Node* node){
    int diff = getHeight(node->getLeft()) - getHeight(node->getRight());
    if (diff > 1) {
        // The subtree is left heavy
        Node* child = node->getLeft();
        int diff_child = getHeight(child->getLeft()) - getHeight(child->getRight());
        if (diff_child > 0) {
            // left-left case
            // 1. Right-rotate (P)
            return rightRotate(node);
        }
        if (diff_child > 0) {
            // left-right case
            // 1. Left-rotate (C)
            node->setLeft(leftRotate(node->getLeft()));
            // 2. Right-rotate (P)
            return rightRotate(node);
        }
    }
    if (diff < -1) {
        // The subtree is right heavy
        Node* child = node->getRight();
        int diff_child = getHeight(child->getLeft()) - getHeight(child->getRight());
        if (diff_child < 0) {
            // right-right case
            // 1. Left-rotate (P)
            return leftRotate(node);
        }
        if (diff_child > 0) {
            // right-left case
            // 1. Right-rotate (C)
            node->setLeft(rightRotate(node->getRight()));
            // 2. Left-rotate (P)
            return leftRotate(node);
        }
    }
    return node;
}


// Reload << operator
std::ostream& operator<<(std::ostream& os, const AVL& avl){
    std::vector<std::string> tree {};
    AVL::Node* root = avl.root;
    int height = avl.getHeight();
    
    avl.add_column(tree, root, height);
    for (auto& column: tree) {
        os << column << std::endl;
    }
    return os;
}

AVL::Node* AVL::rightRotate(Node* parent){
    Node* child = parent->getLeft();
    Node* t2 =  child->getRight(); 

    // Balancing
    child->setRight(parent);
    parent->setLeft(t2);
    
    // Update the heights
    int new_height_parent = std::max(getHeight(parent->getLeft()), getHeight(parent->getRight()))+1;
    parent->setHeight(new_height_parent);
    int new_height_child = std::max(getHeight(child->getLeft()), getHeight(child->getRight()))+1;
    child->setHeight(new_height_child);

    // Return the new top node
    return child;
}

AVL::Node* AVL::leftRotate(Node* child){
    Node* parent = child->getRight();
    Node* t2 =  parent->getLeft(); 

    // Balancing
    parent->setLeft(child);
    child->setRight(t2);
    
    // Update the heights
    int new_height_child = std::max(getHeight(child->getLeft()), getHeight(child->getRight()))+1;
    child->setHeight(new_height_child);
    int new_height_parent = std::max(getHeight(parent->getLeft()), getHeight(parent->getRight()))+1;
    parent->setHeight(new_height_parent);

    // Return the new top node
    return parent;
}

// Add columns to the string to be printed
void AVL::add_column(std::vector<std::string>& columns, Node* node, int height) const{
    if (node==nullptr) {
        return;
    }

    std::string add;
    for (int i = 0; i < 6*height+1; i++){
        if (i == 6*node->getHeight()){
            int node_value = node->getValue();
            add += std::to_string(node_value);
            if (node->getValue() != root->getValue()){
                int digits = count_digits(node_value);
                add += "<";
                std::string lines(5-digits, '-');
                add += lines;
                add += "|";
            }
        } else {
            add += ' ';
        }
    }

    // Calling for the left node
    add_column(columns, node->getLeft(), height);
    columns.push_back(add);
    
    // Calling for the right node
    add_column(columns, node->getRight(), height);
}

int AVL::count_digits(int n) const{
    if (n == 0) {
        return 1;
    }

    int count=0;
    while(n != 0) {
        n /= 10;
        ++count;
    }
    return count;

}


// Node
AVL::Node::Node(int value) {
    this->value = value;
    this->height = 0;
    this->left = nullptr;
    this->right = nullptr;
}

int AVL::Node::getValue() {
    return value;
}

int AVL::Node::getHeight() {
    return height;
}

void AVL::Node::setHeight(int height) {
    this->height = height;
}

AVL::Node* AVL::Node::getLeft() {
    return left;
}

void AVL::Node::setLeft(Node* node) {
    left = node;
}

AVL::Node* AVL::Node::getRight() {
    return right;
}

void AVL::Node::setRight(Node* node) {
    right = node;
}
