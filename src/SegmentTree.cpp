#include "SegmentTree.h"

SegmentTree::Node::Node(int startInterval, int endInterval){
    _startInterval = startInterval;
    _endInterval = endInterval;
    _left = nullptr;
    _right = nullptr;
}

// Constructor
SegmentTree::SegmentTree(std::vector<int> arr){
    // Create a tree using this array
    _root = constructTree(arr, 0, arr.size()-1);
}

// Overload << operator
std::ostream& operator<<(std::ostream& os, const SegmentTree::Node* node){
    std::string str {""};

    if (node->_left != nullptr) {
        str += messageNode(node->_left);
    } else {
        str += "No left child.\n";
    }

    // For current node
    SegmentTree::Node* p_node = (SegmentTree::Node*) node;
    str += messageNode(p_node);

    if (node->_right != nullptr) {
        str += messageNode(node->_right);
    } else {
        str += "No right child.\n";
    }

    os << str << std::endl;

    // "Recursive calls"
    if (node->_left != nullptr) {
        os << node->_left << std::endl;
    }

    if (node->_right != nullptr) {
        os << node->_right << std:: endl;
    }

    return os;
}

std::string messageNode(const SegmentTree::Node* node) {
    std::string msg;
    msg = "Interval=[" + std::to_string(node->_startInterval) + "-" + std::to_string(node->_endInterval) + "] and data=" + std::to_string(node->_data) + " => \n";
    return msg;
}

std::ostream& operator<<(std::ostream& os, const SegmentTree& st){
    SegmentTree::Node* top = st._root;
    os << top << std::endl;
    return os;
}

SegmentTree::Node* SegmentTree::constructTree(std::vector<int>& arr, int start, int end){
    // Base condition
    if (start == end) {
        // Leaf node
        Node* leaf = new Node(start, end);
        leaf->_data = arr[start];
        return leaf;
    }
    
    // Create new node with index you are at
    Node* node = new Node(start, end);
    int mid = (start+end)/2;

    // Update left and right
    node->_left = constructTree(arr, start, mid);
    node->_right = constructTree(arr, mid+1, end);

    // Update data
    node->_data = node->_left->_data + node->_right->_data;

    return node;
}

int SegmentTree::query(int qsi, int qei){
    return query(_root, qsi, qei);
}

int SegmentTree::query(Node* node, int qsi, int qei){
    // Node interval is inside query interval - Case 1
    if (node->_startInterval >= qsi && node->_endInterval <= qei) {
        return node->_data;
    } else if (node->_startInterval > qei || node->_endInterval < qsi) {
        // Node interval is outside query interval - Case 2
        return 0;
    } else {
        return query(node->_left, qsi, qei) + query(node->_right, qsi, qei);
    }
}

void SegmentTree::update(int index, int value) {
   update(_root, index, value); 
}

void SegmentTree::update(Node* node, int index, int value) {
    // 1. Check if index lies in interval
    if (index >= node->_startInterval &&  index <= node->_endInterval) {
        if (index == node->_startInterval && index == node->_endInterval) {
            // Base condition
            node->_data = value;
            return;
        } else {
            // Update
            update(node->_left, index, value);
            update(node->_right, index, value);
            node->_data = node->_left->_data + node->_right->_data;
        }

        
    } else {
        return;
    }
}