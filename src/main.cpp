#include <iostream>
#include <string>

#include "recursion.h"
#include "functions.h"
#include "array_recursion.h"
#include "patterns.h"
#include "templates.h"
#include "sort.h"
#include "pr_unpr.h"
#include "binary_tree.h"
#include "AVL.h"
#include "SegmentTree.h"

int main(){
    std::vector<int> a {3, 8, 6, 7, -2, -8, 4, 9};

    SegmentTree ST(a);
    std::cout << ST << endl;

    int qsi = 1;
    int qei = 6;
    int acc = ST.query(qsi, qei);
    std::cout << "The sum between the indexes [" << qsi << "-" << qei << "] is: " << acc << endl;

    int index = 0;
    int value = 20;
    ST.update(index, value);
    std::cout << "After updating the index " << index << " to " << value << " the sum is: " << ST.query(qsi, qei) << std::endl;

    return 0;
}