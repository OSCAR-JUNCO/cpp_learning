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
#include "graph.h"
#include "leetcode.h"
#include "graph.h"

int main(){
    int x {1};
    int y {1};
    int m {5};
    int n {5};
    int steps {2};

    double probability = findProbability(x, y, m, n, steps);
    std::cout << "The probability that in the next " << steps << " moves, we never cross the matrix boundaries";
    std::cout << " of a " << m << "*" << n << " matrix, starting from the position (" << x << "," << y << ") is: ";
    std::cout << probability << std::endl;
}