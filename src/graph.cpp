#include "graph.h"

Graph::Graph(int vertices) {
    _V = vertices;
    for (int i = 0; i < vertices; i++)
    {
        // Create the head node
        Node* head = new Node;
        head->val = i;
        head->next = nullptr;

        // Add head to the head of the Adjacency List
        AdjList* list = new AdjList;
        list->head = head;

        // Add the Adjacency List to the vector
        _adjList.push_back(list);
    }
}

void Graph::addEdge(int u, int v) {
    Node* newNode = new Node;
    newNode->val = v;
    newNode->next = nullptr;

    AdjList* currentList = _adjList[u];
    Node* node = currentList->head;
    while (node->next != nullptr) {
        node = node->next;
    }
    node->next = newNode;
}


void Graph::addEdgeUndirected(int u, int v) {
    addEdge(u, v);
    addEdge(v, u);
}


void Graph::BFS(int start) {
    // Mark all vertices as not visited
    std::vector<bool> visited(_V, false);
    
    // Create a queue for BFS
    std::queue<int> bfs_queue;

    // Mark the current node visited and enqueue it 
    visited[start] = true;
    bfs_queue.push(start);

    std::cout << "BFS traversal from node " << start << " : " << std::endl;
    while(!bfs_queue.empty()) {
        // Dequeue a vertex from queue and print it
        start = bfs_queue.front();
        std::cout << start << " ";
        bfs_queue.pop();

        // Get all adjacent vertices from the dequeued vertex start
        // If an adjacent vertex has not been visited, then mark it visited and enqueue it
        Node* node = _adjList[start]->head;
        while(node != nullptr) {
            int node_val = node->val;
            if(!visited[node_val]) {
                visited[node_val] = true;
                bfs_queue.push(node_val);
            }
            node = node->next;
        }
    }
    std::cout << std::endl;
    
}


void Graph::DFS(int v){
    std::cout << "DFS traversal from node " << v << " :" << std::endl;

    // Mark all the vertices as not visited
    std::vector<bool> visited(_V, false);
    
    // Call the recursive helper function to print DFS traversal
    DFS_helper(v, visited);
    std::cout << std::endl;
}

void Graph::DFS_helper(int v, std::vector<bool>& visited){
    // Mark the current node as visited and print it
    visited[v] = true;
    std::cout << v << " ";

    Node* node = _adjList[v]->head;
    // Recur for all the vertices adjacent to this vertex
    while (node != nullptr) {
        v = node->val;
        if (!visited[v]) {
            DFS_helper(v, visited);
        }
        node = node->next;
    }
}


void Graph::topologicalSort() {
    std::cout << "Topological sort:" << std::endl;

    std::stack<int> ts_stack;

    // Mark all the vertices as not visited
    std::vector<bool> visited(_V, false);

    // Call the recursive helper function to store Topological Sort starting from all vertices one by one
    for (int i = 0; i < visited.size(); i++)
    {
        if (!visited[i]) {
            topologicalSort_helper(i, visited, ts_stack);
        }
    }

    // Print contents of the stack
    while (!ts_stack.empty()) {
        std::cout << ts_stack.top() << " ";
        ts_stack.pop();
    }
    std::cout << std::endl;
    
}

void Graph::topologicalSort_helper(int v, std::vector<bool>& visited, std::stack<int>& ts_stack) {
    // Mark the node as visited
    visited[v] = true;

    Node* node = _adjList[v]->head;
    while (node != nullptr) {
        int val = node->val;
        if (!visited[val]) {
            topologicalSort_helper(val, visited, ts_stack);
        }
        node = node->next;
    }

    // Push current node in the stack which stores result
    ts_stack.push(v);
}

std::ostream& operator<<(std::ostream& os, const Graph& graph){
    os << "Graph with " << graph._V << " vertices:" << std::endl;
    for (auto& list: graph._adjList) {
        Node* node = list->head;
        while (node != nullptr) {
            os << node->val << "->";
            node = node->next;
        }
        os << "/" << std::endl;
    }
    return os;
}