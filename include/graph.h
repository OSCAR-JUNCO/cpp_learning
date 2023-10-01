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
public:
    int _V; // Number of vertices
    std::vector<AdjList*> _adjList; // Adjacency list

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
    
private:
    void DFS_helper(int v, std::vector<bool>& visited);
    void topologicalSort_helper(int v, std::vector<bool>& visited, std::stack<int>& ts_stack);

};

// Overload << operator for the Graph class
std::ostream& operator<<(std::ostream& os, const Graph& graph);

#endif // GRAPH_H