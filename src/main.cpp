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
    Graph graph(4);
    graph.addEdgeUndirected(0,1);
    graph.addEdgeUndirected(0,2);
    graph.addEdgeUndirected(1,3);
    graph.addEdgeUndirected(1,2);
    graph.addEdgeUndirected(2,3);

    // Number of triangles
    int triangles = graph.trianglesInGraph();
    // Number of squares
    std::cout << triangles << std::endl;
}
