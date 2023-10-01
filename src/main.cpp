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
    Graph graph(9);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(1,4);
    graph.addEdge(2,5);
    graph.addEdge(4,6);
    graph.addEdge(4,7);
    graph.addEdge(4,8);
    
    // Printing graph
    std::cout << graph;

    int u = 4;
    int v = 7;

    std::string same = graph.same_path(u, v) ? " ARE " : " ARE NOT ";

    std::cout << "The nodes " << u << " and " << v << same << "on the same path." << std::endl;

}