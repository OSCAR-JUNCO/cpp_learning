#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H

#include <vector>
#include <iostream>
#include <string>

class SegmentTree {
public:
    class Node {
    public:
        int _data;
        int _startInterval;
        int _endInterval;
        Node* _left;
        Node* _right;

        Node(int startInterval, int endInterval);

    };

    Node* constructTree(std::vector<int>& arr, int start, int end);
    Node* _root;
    
    SegmentTree(std::vector<int> arr);
    int query(int qsi, int qei);
    void update(int index, int value);

private:
    int query(Node* node, int qsi, int qei);
    void update(Node* node, int index, int value);

};

// Overload << operator
std::ostream& operator<<(std::ostream& os, const SegmentTree::Node* node);
std::string messageNode(const SegmentTree::Node* node);
std::ostream& operator<<(std::ostream& os, const SegmentTree& st);

#endif //SEGMENTTREE_H