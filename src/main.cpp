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
    Graph graph(6);
    graph.addEdge(0,1);
    graph.addEdgeUndirected(0,2);
    graph.addEdgeUndirected(0,3);
    graph.addEdge(0,5);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(1,4);
    graph.addEdge(2,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(5,1);
    graph.addEdge(5,2);
    graph.addEdgeUndirected(4,5);
    
    // Assign directions
    graph.assignDirections();

    // Print the Adjacency Matrix after assign directions
    graph.printAdjMatrix();
    std::cout << graph;

}