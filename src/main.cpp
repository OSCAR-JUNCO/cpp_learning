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
    graph.addEdge(0,1);
    graph.addEdge(0,3);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(3,0);
    graph.addEdge(3,4);
    graph.addEdge(4,4);

    graph.printAdjMatrix();

    // Check if an undirected graph is cyclic using colors
    bool is_cyclic = graph.isCyclicDirected_colors();

    std::string cyclic = "IS";
    if (!is_cyclic) {
        cyclic = "IS NOT";
    }
    std::cout << "The graph " << cyclic << " cyclic." << std::endl;


}
