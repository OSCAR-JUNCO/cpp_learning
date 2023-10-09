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

private:
    void DFS_helper(int v, std::vector<bool>& visited);
    void DFS_util(int v, std::vector<bool>& visited);
    void topologicalSort_helper(int v, std::vector<bool>& visited, std::stack<int>& ts_stack);
    void updateAdjMatrix();
    void updateAdjList();
    // Find polygons in an unconnected graph
    int polygonsInGraph(int sides);
    // DFS cycle detection
    bool isCyclic_util(int v, std::vector<bool>& visited, std::vector<bool>& recStack);

};

// Overload << operator for the Graph class
std::ostream& operator<<(std::ostream& os, const Graph& graph);

// Functions to operate matrices
std::vector<std::vector<int>> multiplyMatrices(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B);
std::vector<std::vector<int>> raiseMatrix(std::vector<std::vector<int>>& A, int power);
int trace(std::vector<std::vector<int>>& A);

#endif // GRAPH_H