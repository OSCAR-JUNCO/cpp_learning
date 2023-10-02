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

int main(){
    int digit = 4;
    std::vector<string> combinations = dice_combinations(digit);

    for (auto combination: combinations) {
        std::cout << combination << std::endl;
    }
    std::cout << std::endl;
}