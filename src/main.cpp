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

int main(){
    Graph graph(6);
    graph.addEdgeUndirected(0,1);
    graph.addEdgeUndirected(0,2);
    graph.addEdgeUndirected(1,3);
    graph.addEdgeUndirected(1,4);
    graph.addEdgeUndirected(2,4);
    graph.addEdgeUndirected(3,4);
    graph.addEdgeUndirected(3,5);
    graph.addEdgeUndirected(4,5);
    
    // Printing graph
    std::cout << graph;

    // Breadth-First Traversal
    graph.BFS(0);

    // Depth-First Traversal
    graph.DFS(0);

    // Creating a directed acyclic graph
    Graph da_graph(10);
    da_graph.addEdge(0, 1);
    da_graph.addEdge(0, 5);
    da_graph.addEdge(1, 7);
    da_graph.addEdge(3, 2);
    da_graph.addEdge(3, 4);
    da_graph.addEdge(3, 8);
    da_graph.addEdge(3, 8);
    da_graph.addEdge(4, 8);
    da_graph.addEdge(6, 0);
    da_graph.addEdge(6, 2);
    da_graph.addEdge(8, 2);
    da_graph.addEdge(9, 4);

    // Print the DAG
    std::cout << da_graph;

    // Topological sort for a DAG
    da_graph.topologicalSort();


    return 0;
}