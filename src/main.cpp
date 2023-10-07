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
    Graph graph(7);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(4,1);
    graph.addEdge(5,2);
    graph.addEdge(5,6);
    graph.addEdge(6,0);
    graph.addEdge(6,4);
    
    // Print graph
    std::cout << graph;

    // Mother vertices
    std::vector<int> motherVertices = graph.findMotherVertices();
    int n = motherVertices.size();
    if (n == 0) {
        std::cout << "The graph has no mother vertices." << std::endl; 
    } else {
        std::cout << "The graph has " << n << " mother vertex(ices): ";
        for (auto v: motherVertices) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}