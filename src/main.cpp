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

int main() {
    Graph graph(5);
    graph.addEdgeUndirected(0,1);
    graph.addEdgeUndirected(0,2);
    graph.addEdgeUndirected(0,3);
    graph.addEdgeUndirected(1,2);
    graph.addEdgeUndirected(3,4);

    graph.printAdjMatrix();

    // Check if the graph is a tree
    std::string tree = "IS";
    if (!graph.isTree()) {
        tree = "IS NOT";
    }

    std::cout << "The graph " << tree << " a tree." << std::endl;
}
