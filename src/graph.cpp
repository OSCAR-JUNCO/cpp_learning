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

void Graph::DFS_iterative(int v) {
    std::cout << "Iterative DFS: ";

    // Created the visited vector
    std::vector<int> visited(_V, false);

    // Create a stack for DFS
    std::stack<int> dfs_stack;

    // Push source into the stack
    dfs_stack.push(v);

    // Push the source vertex into the stack
    while(!dfs_stack.empty()) {
        // Print and pop the current vertex
        int current = dfs_stack.top();
        dfs_stack.pop();

        // Mark as visited the current node
        visited[current] = true;
        std::cout << current << " ";


        Node* head = _adjList[current]->head;
        Node* adjacent = head->next;
        while(adjacent != nullptr) {
            int adjVal = adjacent->val;
            if (!visited[adjVal]) {
                dfs_stack.push(adjVal);
            }
            adjacent = adjacent->next;
        } 
    }
    std::cout << std::endl;
}

void Graph::topologicalSort() {
    std::cout << "Topological sort:" << std::endl;

    std::stack<int> ts_stack;

    // Mark all the vertices as not visited
    std::vector<bool> visited(_V, false);

    // Call the recursive helper function to store Topological Sort starting from all vertices one by one
    for (int i = 0; i < _V; i++)
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

    Node* head = _adjList[v]->head;
    Node* node = head->next;
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
        std::cout << i << " |";
        for (int j = 0; j < _V; ++j) {
            char val = '1';
            if (_adjMatrix[i][j] == 0) val = ' ';
            std::cout << val << "|";
        }
        std::cout << std::endl;
    }
}

void Graph::assignDirections() {
    // Perform topological sort on the graph considering only the directed edges
    std::vector<std::vector<int>> adjMatrix_temp = _adjMatrix;
    for (int i = 0; i < _V; ++i) {
        for (int j = 0; j < _V; ++j) {
            // The edge is undirected
            if (_adjMatrix[i][j] == 1 && _adjMatrix[j][i] == 1) {
                // Remove undirected edge
                _adjMatrix[i][j] = 0;
                _adjMatrix[j][i] = 0;
            }
        }
    }
    updateAdjList();
    topologicalSort();

    // Find the undirected edges by iterating through the previously stored Adjacency Matrix
    for (int i = 0; i < _V; ++i) {
        for (int j = 0; j < _V; ++j) {
            // The edge is undirected
            if (adjMatrix_temp[i][j] == 1 && adjMatrix_temp[j][i] == 1) {
                // Find the position of the i node in the topological sort
                auto pos_u = std::find(_topologicalSort.begin(), _topologicalSort.end(), i);
                // Find the position of the j node in the topological sort
                auto pos_v = std::find(_topologicalSort.begin(), _topologicalSort.end(), j);

                // Assign direction
                if (pos_u < pos_v) {
                    adjMatrix_temp[j][i] = 0;
                } else {
                    adjMatrix_temp[i][j] = 0;
                }
            }
        }
    }

    // Update the Adjacency Matrix
    _adjMatrix = adjMatrix_temp;

    // Update the Adjacency List
    updateAdjList();

    // Messages
    std::cout << "Directions assigned!" << std::endl;
}

std::vector<int> Graph::findMotherVertices() {
    std::vector<int> motherVertices = {};

    // Do DFS traversal (topological sort), last finished vertex is the first vertex of the topological sort
    topologicalSort();

    // If there exist a mother vertex (or vertices) in given
    // graph, then v must be one (or one of them)

    // Now check which of the first vertices in the Topological Sort are mother vertices
    // if there are. We basically check if every vertex is reachable from that particular vertex v or not.

    // Create the visited vector with all their values set to false and do
    // DFS beginning from v 

    for (int i = 0; i < _V; i++) {
        int v = _topologicalSort[i];
        std::vector<bool> visited(_V, false);

        // Do DFS
        DFS_util(v, visited);

        // If all the nodes are visited, store the node in the motherVertices array
        if (std::equal(visited.begin()+1, visited.end(), visited.begin())) {
            motherVertices.push_back(v);
        } else {
            break;
        }
    }

    return motherVertices;
}

void Graph::DFS_util(int v, std::vector<bool>& visited) {
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices adjacent to current vertex
    Node* head = _adjList[v]->head;
    Node* node = head->next;
    while(node != nullptr) {
        int adjacent = node->val;
        // Visit adjacent node if not visited yet
        if (!visited[adjacent]) {
            DFS_util(adjacent, visited);
        }
        // Move to next 
        node = node->next;
    }
}

// Find number of triangles in an undirected graph
int Graph::trianglesInGraph() {
    int triangles = polygonsInGraph(3);
    std::cout << "The graph has " << triangles << " internal triangles." << std::endl;
    return triangles;
}

// Check if a graph contains a cycle
bool Graph::isCyclic() {
    std::vector<bool> visited(_V, false);
    std::vector<bool> recStack(_V, false);
    
    // Call the recursive helper function to detect cycle    
    for (int i = 0; i < _V; i++) {
        if (isCyclic_util(i, visited, recStack)) {
            return true;
        }
    }

    return false; 
}

bool Graph::isCyclicUndirected() {
    // Creating _V subsets 
    std::vector<int> parents(_V, -1);

    // Iterate through all the edges of the graph, _adjMatrix, find subset of both
    // edge vertices, if both subsets are the same, then there is a cycle
    for (int i = 0; i < _V; i++)
    {
        for (int j = 0; j < _V; j++)
        {
            // Only iterate the
            if (_adjMatrix[i][j] == 1 && j > i) { 
                int x_set = find(parents, i);
                int y_set = find(parents, j);
                if (x_set == y_set) {
                    return true;
                } else {
                    subset_union(parents, x_set, y_set);
                }
            }
        } 
    }
    return false;
    
}

bool Graph::isCyclicUndirectedDFS() {
    // Visited array
    std::vector<bool> visited(_V, false);

    // Iterate through all the neighbors
    for (int i = 0; i < _V; i++)
    {
        // Take into account unconnected graphs
        if (!visited[i]) {
            // Parent for node '0' is '-1'
            if (isCyclicUndirectedDFS_util(i, visited, -1)) {
                return true;
            }
        }
    }
    return false;
    
}

bool Graph::isCyclicDirected_colors() {
    // Create the vector of colors
    std::vector<Color> color(_V, WHITE);

    // Do DFS beginning with all the vertices
    for (int i = 0; i < _V; i++)
    {
        if (color[i] == WHITE) {
            if (DFS_colors_util(i, color)) {
                return true;
            }
        }
    }
    return false;    
}

bool Graph::DFS_colors_util(int v, std::vector<Color>& color) {
    // Mark vertex as beeing visited
    color[v] = GRAY;

    // Visit the adjacent vertices
    Node* head = _adjList[v]->head;
    Node* adjacent = head->next;
    while(adjacent != nullptr) {
        int adj_val = adjacent->val;

        // If the adjacent is not visited and there is a back edge in the subgraph 
        // rooted by that adjacent
        if (color[adj_val] == WHITE && DFS_colors_util(adj_val, color)) {
            return true;
        // If there is a back edge
        } else if (color[adj_val] == GRAY) {
            return true;
        }
        adjacent = adjacent->next;
    }
    // Mark vertex as visited after visiting all its adjacent nodes
    color[v] = BLACK;

    return false;
}

// Find the SCC (Strong connected components)
std::vector<std::vector<int>> Graph::findSCC() {
    // Create the output vector
    std::vector<std::vector<int>> scc;    

    // Create the visited array
    std::vector<bool> visited(_V, false);

    // 1. Create an empty stack
    std::stack<int> scc_stack;

    // 2. Do DFS for each vertex to fill the stack
    for (int i = 0; i < _V; i++) {
        if (!visited[i]) {
            topologicalSort_helper(i, visited, scc_stack);
        }
    }

    // 3. Create a transposed graph from the current one
    Graph gt(*this);
    std::vector<std::vector<int>> adjMatrix_transposed = getTranspose(gt._adjMatrix);
    gt._adjMatrix = adjMatrix_transposed;
    gt.updateAdjList();

    // 4. Pop one by one the vertices
    for (int i = 0; i < _V; i++) {
        visited[i] = false;
    }
    
    while (!scc_stack.empty()) {
        int v = scc_stack.top();
        scc_stack.pop();

        // Create a vector to store the vertices of a single scc
        std::vector<int> single_scc;

        if (!visited[v]) {
            gt.DFS_scc_util(v, visited, single_scc);
        }
        if (!single_scc.empty())
            scc.push_back(single_scc);
        
    } 
    return scc;
}

// Check if an undirected graph is a tree
bool Graph::isTree() {
    // An undirected graph is a tree if:
    // - There is no cycle
    // - The graph is connected

    return (!isCyclicUndirected() && isConnected());
}

bool Graph::isConnected() {
    // Create the visited array
    std::vector<bool> visited(_V, false);

    // Check if all the nodes are reachable from the source vertex
    // If all nodes are reached from 0, it means that all the nodes are reachable from every node as 
    // the graph is undirected
    DFS_util(0, visited);

    // If there is one vertex not visited return false
    bool hasFalse = std::any_of(visited.begin(), visited.end(), [](bool element) {
        return !element; // Check if the element is false
    });

    if (hasFalse) {
        return false;
    }
    return true;    
}

void Graph::DFS_scc_util(int v, std::vector<bool>& visited, std::vector<int>& scc) {
    // Mark the vertex as visited
    visited[v] = true;

    // Add the visited vertex to the Strong Connected Component
    scc.push_back(v);

    // Recur for all the adjacent vertices
    Node* head = _adjList[v]->head;
    Node* node = head->next;
    while(node != nullptr) {
        int adjacent = node->val;
        if (!visited[adjacent]) {
            DFS_scc_util(adjacent, visited, scc);
        }
        node = node->next;
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
        while(head){
            Node* temp = head;
            head = head->next;
            delete temp; // Deallocate memory
        }

        _adjList[i]->head = nullptr;
    }

    // Updating the Adjacency List from the Adjacency Matrix
    for (int i = 0; i < _V; ++i) {
        Node* head = new Node;
        head->val = i;
        head->next = nullptr;

        for (int j = 0; j < _V; ++j) {
            if (_adjMatrix[i][j] == 1) {
                Node* newNode = new Node;
                newNode->val = j;
                newNode->next = nullptr;

                Node* node = head;
                while (node->next != nullptr) {
                    node = node->next;
                }
                node->next = newNode;
            }
            _adjList[i]->head = head;
        }
    } 
}


// Find polygons in an unconnected graph
int Graph::polygonsInGraph(int sides) {

    // Raise the matrix
    std::vector<std::vector<int>> A = raiseMatrix(_adjMatrix, sides);

    // Calculate number of polygons
    int polygons = trace(A)/(sides*2);

    return polygons;
}


// Find the bridge edges in a graph
std::vector<std::pair<int, int>> Graph::findBridges(){
    // Create the ans vector
    std::vector<std::pair<int, int>> bridges;

    // Create the vectors
    std::vector<bool> visited(_V, false);
    std::vector<int> discovery(_V, 0);
    std::vector<int> low(_V, 0);
    std::vector<int> parent(_V, -1);
    
    // Do the DFS traversal
    for (int i = 0; i < _V; i++)
    {
        if (!visited[i]) {
            findBridges_util(i, visited, discovery, low, parent, bridges);
        }
    }
    
    return bridges;
}

void Graph::findBridges_util(int u, std::vector<bool>& visited, std::vector<int>& discovery, std::vector<int>& low, std::vector<int>& parent, std::vector<std::pair<int, int>>& bridges){
    // Mark node as visited
    visited[u] = true;

    // Create a static variable to assign the discovery and low time
    static int time = 0;

    // Assign the discovery and low time
    discovery[u] = low[u] = ++time;

    Node* head = _adjList[u]->head;
    Node* adjacent = head->next;
    while (adjacent != nullptr) {
        int v = adjacent->val;
        
        if (!visited[v]) {
            // Recursive call, assign the parent
            parent[v] = u;
            findBridges_util(v, visited, discovery, low, parent, bridges);

            // Assign min low to the current vertex
            low[u] = std::min(low[u], low[v]);

            // Compare discovery[u] vs low[v]
            if (discovery[u] < low[v]) {
                // Bridge found
                std::pair<int, int> bridge;
                bridge.first = u;
                bridge.second = v;
                bridges.push_back(bridge);
            }
        } else if (v != parent[u]) {
            low[u] = std::min(low[u], discovery[v]);
        }

        // Next adjacent
        adjacent = adjacent->next;
    }
}

// DFS cycle detection
bool Graph::isCyclic_util(int v, std::vector<bool>& visited, std::vector<bool>& recStack) {
    // First if to consider unconnected graphs
    if(!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        Node* head = _adjList[v]->head;
        Node* node = head->next;
        while (node != nullptr) {
            int neighbour = node->val;
            if (!visited[neighbour] && isCyclic_util(neighbour, visited, recStack)) {
                return true;
            } else if (recStack[neighbour]) {
                return true; 
            }
            node = node->next;
        } 
    }
    recStack[v] = false;
    return false;
}


bool Graph::isCyclicUndirectedDFS_util(int v, std::vector<bool>& visited, int parent) {
    // Mark node as visited
    visited[v] = true;

    Node* head = _adjList[v]->head;
    Node* node = head->next;
    while(node != nullptr) {
        int value = node->val;
        // If an adjacent is not visited, then recur for that adjacent node
        if (!visited[value]) {
            if (isCyclicUndirectedDFS_util(value, visited, v)) {
                return true;
            }
        }
        // If an adjacent is visited and not parent of current vertex, then we detect a cycle
        else if (value != parent) {
            return true;
        }
        node = node->next;
    }
    return false;
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


// Functions to operate matrices
std::vector<std::vector<int>> multiplyMatrices(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B) {
    int m = A.size();
    int p = B[0].size(); 
    std::vector<int> row(p);
    std::vector<std::vector<int>> C(m, row);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
        
    }
    return C;
}

std::vector<std::vector<int>> raiseMatrix(std::vector<std::vector<int>>& A, int power) {
    std::vector<std::vector<int>> C = A;
    power--;
    while (power > 0) {
        C = multiplyMatrices(C, A);
        power--;
    }
    return C;

}

int trace(std::vector<std::vector<int>>& A) {
    int sum = 0;
    int n = A.size();

    for (int i = 0; i < n; ++i) {
        sum += A[i][i];
    }
    return sum;
}

std::vector<std::vector<int>> getTranspose(const std::vector<std::vector<int>>& A) {
    int n = A.size();
    int m = A[0].size();
    std::vector<int> row(n);
    std::vector<std::vector<int>> ans(m, row);

    // Recur all the A matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[j][i] = 0;
            if (A[i][j] == 1) {
                ans[j][i] = 1;
            }
        }
    }
     
    return ans;    
}

// Functions to work with sets
int find(std::vector<int>& parents, int v) {
    if (parents[v] == -1) {
        return v;
    }
    return find(parents, parents[v]);
}

void subset_union(std::vector<int>& parents, int x, int y) {
    int x_set = find(parents, x);
    int y_set = find(parents, y);
    parents[x_set] = y_set;
}