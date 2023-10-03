#include "graph.h"

Graph::Graph(int vertices) {
    _V = vertices;

    // Help to define the inTime and outTime vectors
    _timer = 0;
    _inTime.resize(_V);
    _outTime.resize(_V);

    // Define the number of rows of the Adjacency Matrix
    _adjMatrix.resize(_V);

    for (int i = 0; i < vertices; i++)
    {
        // Define the number of columns of the Adjacency Matrix
        _adjMatrix[i].resize(_V, 0);
        
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


    // Define the size of the topological sort vector
    _topologicalSort.resize(_V);
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

    _adjMatrix[u][v] = 1;
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
    // Increment the timer and assign inTime
    ++_timer;
    _inTime[v] = _timer;

    // Mark the current node as visited and print it
    visited[v] = true;
    std::cout << v << " ";

    Node* node = _adjList[v]->head;
    // Recur for all the vertices adjacent to this vertex
    while (node != nullptr) {
        int val = node->val;
        if (!visited[val]) {
            DFS_helper(val, visited);
        }
        node = node->next;
    }

    // Increment the timer and assign outTime
    ++_timer;
    _outTime[v] = _timer;
}


void Graph::topologicalSort() {
    std::cout << "Topological sort:" << std::endl;

    std::stack<int> ts_stack;

    // Mark all the vertices as not visited
    std::vector<bool> visited(_V, false);

    // Call the recursive helper function to store Topological Sort starting from all vertices one by one
    for (size_t i = 0; i < visited.size(); i++)
    {
        if (!visited[i]) {
            topologicalSort_helper(i, visited, ts_stack);
        }
    }

    // Print and store contents of the stack
    int i = 0;
    while (!ts_stack.empty()) {

        int val = ts_stack.top();
        std::cout << val << " ";

        // Store contents of the stack
        _topologicalSort[i++] = val;

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

bool Graph::same_path(int u, int v) {
    DFS(0);
    return (_inTime[v] < _inTime[u] && _outTime[v] > _outTime[u]) || 
           (_inTime[u] < _inTime[v] && _outTime[u] > _outTime[v]);
}


void Graph::printAdjMatrix() {
    std::cout << "Adjacency Matrix: " << std::endl;

    std::cout << "   ";
    for (int i = 0; i < _V; ++i) {
        std::cout << i << "|";
    }
    std::cout << std::endl;
    int total_char = _V*2+3;
    for (int i = 0; i < total_char; ++i) {
        std::cout << "_";
    }
    std::cout << std::endl;

    for (int i = 0; i < _V; ++i) {
        std::cout << i << "| ";
        for (int j = 0; j < _V; ++j) {
            char val = '1';
            if (_adjMatrix[i][j] == 0) val = ' ';
            std::cout << val << "|";
        }
        std::cout << std::endl;
    }
}



void Graph::updateAdjMatrix() {
    // Cleaning the Adjacency Matrix
    for (int i = 0; i < _V; ++i) {
        for (int j = 0; j < _V; ++i) {
            _adjMatrix[i][j] = 0;
        }
    }

    // Updating the Adjacency Matrix from the Adjacency List
    for (int i = 0; i < _V; ++i) {
        AdjList* adjList = _adjList[i];
        Node* node = adjList->head;
        while (node != nullptr) {
            node = node->next;
            _adjMatrix[i][node->val] = 1;
        }
    } 
}
void Graph::updateAdjList() {
    // Cleaning the Adjacency List
    for (int i = 0; i < _V; ++i) {
        Node* head = _adjList[0]->head;
        Node* node = head->next;
        while (node != nullptr) {
            Node* temp = node;
            node = node->next;
            delete temp;
        }
    }

    // Updating the Adjacency List from the Adjacency Matrix
    for (int i = 0; i < _V; ++i) {
        Node* head = _adjList[i]->head;
        for (int j = 0; i < _V; ++i) {
            if (_adjMatrix[i][j] == 1) {
                Node* newNode = new Node;
                newNode->val = j;
                newNode->next = nullptr;

                Node* node = head->next;
                while (node != nullptr) {
                    node = node->next;
                }
                node = newNode;
            }
        }
    } 
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