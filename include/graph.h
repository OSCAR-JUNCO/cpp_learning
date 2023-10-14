#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
#include <iostream>
#include <stack>

struct Node{
    int val;
    struct Node* next;
};

struct AdjList {
    struct Node* head;
};

enum Color {
    WHITE, // 0
    GRAY,  // 1
    BLACK  // 2
};

class Graph {
    int _timer;
    std::vector<int> _inTime;
    std::vector<int> _outTime;

    // Store topological sort
    std::vector<int> _topologicalSort;

public:
    int _V; // Number of vertices
    std::vector<AdjList*> _adjList; // Adjacency list
    std::vector<std::vector<int>> _adjMatrix;

    // Constructor
    Graph (int vertices);

    // Add an edge to the graph
    void addEdge(int u, int v);
    void addEdgeUndirected(int u, int v);
    // Add a vertex to the the graph
    void addVertex(int val);

    // Breadth-First Traversal
    void BFS(int start);

    // Depth-First Traversal
    void DFS(int v);
    void DFS_iterative(int v);

    // Topological sort
    void topologicalSort();

    // Check if two nodes are on the same path in a tree-like graph
    bool same_path(int u, int v);

    // Print Adjacency Matrix
    void printAdjMatrix();

    // Assign directions to undirected edges so that the directed graph remains acyclic
    void assignDirections();

    // Find mother vertices of a graph
    std::vector<int> findMotherVertices();

    // Find number of triangles in an undirected graph
    int trianglesInGraph();

    // Check if a graph contains a cycle
    bool isCyclic();
    bool isCyclicUndirected();
    bool isCyclicUndirectedDFS();
    bool isCyclicDirected_colors();

    // Find the SCC (Strong connected components)
    std::vector<std::vector<int>> findSCC();

private:
    void DFS_helper(int v, std::vector<bool>& visited);
    void DFS_util(int v, std::vector<bool>& visited);
    bool DFS_colors_util(int v, std::vector<Color>& color);
    void DFS_scc_util(int v, std::vector<bool>& visited, std::vector<int>& scc);
    void topologicalSort_helper(int v, std::vector<bool>& visited, std::stack<int>& ts_stack);
    void updateAdjMatrix();
    void updateAdjList();
    // Find polygons in an unconnected graph
    int polygonsInGraph(int sides);
    // DFS cycle detection
    bool isCyclic_util(int v, std::vector<bool>& visited, std::vector<bool>& recStack);
    bool isCyclicUndirectedDFS_util(int v, std::vector<bool>& visited, int parent);

};

// Overload << operator for the Graph class
std::ostream& operator<<(std::ostream& os, const Graph& graph);

// Functions to operate matrices
std::vector<std::vector<int>> multiplyMatrices(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B);
std::vector<std::vector<int>> raiseMatrix(std::vector<std::vector<int>>& A, int power);
int trace(std::vector<std::vector<int>>& A);
std::vector<std::vector<int>> getTranspose(const std::vector<std::vector<int>>& A);

// Functions to work with sets
int find(std::vector<int>& parents, int v);
void subset_union(std::vector<int>& parents, int x, int y);

#endif // GRAPH_H