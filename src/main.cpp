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
    std::string digits {"23"};
    std::vector<std::string> combinations = letterCombinations(digits);

    std::cout << "[";
    for (auto comb: combinations) {
        std::cout << "'" << comb << "'" << ", ";
    }
    std::cout << "]" << std::endl;
}