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
    Graph graph(9);
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(2,3);
    graph.addEdge(3,0);
    graph.addEdge(2,4);
    graph.addEdge(4,5);
    graph.addEdge(5,6);
    graph.addEdge(6,4);
    graph.addEdge(7,6);
    graph.addEdge(7,8);

    graph.printAdjMatrix();

    // Get the SCC (Strong Connected Components)
    std::vector<std::vector<int>> scc = graph.findSCC();

    std::cout << "Printing the SCC of the graph: " << std::endl;
    for (int i = 0; i < scc.size(); i++) {
        std::cout << i << ". ";
        for (int& v: scc[i]) {
            std::cout  << v << " ";
        }
        std::cout << std::endl;
    }
    
}
