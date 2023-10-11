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
    graph.addEdgeUndirected(1,3);
    graph.addEdgeUndirected(1,4);
    graph.addEdgeUndirected(3,4);

    graph.printAdjMatrix();

    // Check if an undirected graph is cyclic
    bool is_cyclic = graph.isCyclicUndirected();

    std::string cyclic = "IS";
    if (!is_cyclic) {
        cyclic = "IS NOT";
    }
    std::cout << "The graph " << cyclic << " cyclic." << std::endl;


}
