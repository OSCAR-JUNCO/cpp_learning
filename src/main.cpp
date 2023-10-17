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
    Graph graph(6);
    graph.addEdgeUndirected(0,1);
    graph.addEdgeUndirected(1,2);
    graph.addEdgeUndirected(1,5);
    graph.addEdgeUndirected(2,3);
    graph.addEdgeUndirected(3,4);
    graph.addEdgeUndirected(3,5);

    graph.printAdjMatrix();

    // Find the bridges of the edge
    std::vector<std::pair<int, int>> bridges = graph.findBridges();
    std::cout << "The graph has " << bridges.size() << " bridges: " << std::endl;
    for (auto& bridge: bridges) {
        std::cout << bridge.first << "->" << bridge.second << std::endl;
    }
}
