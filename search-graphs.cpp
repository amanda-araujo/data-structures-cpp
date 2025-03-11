//
// Created by Amanda Araujo on 10/03/2025.
// Ref. https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
//
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// Graph Representation: Adjacency Lists
class Graph {
    map<int, vector<int>> adjList; // Attribute (private)
public:
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // undirected
    }
    void printGraph() {
        for (auto i : adjList) { // Iterate over vertices
            cout << i.first << " -> ";
            for (auto j : i.second) { // Iterate over linked list (neighbors)
                cout << j << " ";
            }
            cout << endl;
        }
    }
    map<int, vector<int>> getAdjList() { // Getter method
        return adjList;
    }

};

// Function prototypes
vector<int> BFS(Graph& g, int v0);
/* const map<int, vector<int>>&    : pass by const reference,
 * no modifications on the original, don't create copy, faster */
vector<int> DFS(Graph& g, int v0);

int main () {
    // Create graph
    Graph g;

    // Adding edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(0, 5);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Print graph
    g.printGraph();

    // Traversal algorithms
    int v0 = 0; // Initial vertex

    // BFS: Breadth-First Search (Busca em Largura)
    cout << "BFS from vertex " << v0 << ": " << endl;
    vector<int> bfs = BFS(g, v0); // Graph, initial vertex
    for (auto i : bfs) { cout << i << " "; }
    cout << endl;

    // DFS: Deep-First Search (Busca em Profundidade)
    cout << "DFS from vertex " << v0 << ": " << endl;
    vector<int> dfs = DFS(g, v0);
    for (auto i : dfs) { cout << i << " "; }
    cout << endl;

    return 0;
}

vector<int> BFS(Graph& g, int v0) {
    // Input: graph of class Graph, initial vertex
    // Output: BFS visit order from v0 (traversal)
    // Ps: works for connected graphs

    // Get adjacency list from Graph
    map<int, vector<int>> adjList = g.getAdjList();
    int n = adjList.size(); // Size of map; number of vertices

    // Structures declaration
    vector<int> res;  // Result: stores traversal BFS
    queue<int> queue; // Queue for BFS

    // Initialization: all vertices as not visited
    vector<bool> visited(n, false); // Flag
    visited[v0] = true; // Initial vertex visisted
    queue.push(v0); // Add initial vertex to the queue

    // Iteration over the queue
    while (!queue.empty()) {

        // Remove current vertex from the queue
        int curr = queue.front(); // First vertex of the queue
        queue.pop();            // Remove first element
        res.push_back(curr); // Add vertex at the traversal

        // Get adjacent vertices and visit the unvisited
        for (int u : adjList[curr]) { // Adjacent vertices
            if (!visited[u]) {  // Not visited
                visited[u] = true; // Already visited
                queue.push(u); // Add vertex to the queue
            }
        }
    }
    return res;
}

vector<int> DFS(Graph& g, int v0) {
    // Input: graph of class Graph, initial vertex
    // Output: DFS traversal from v0

    // Getting adjacency list from Graph
    map<int, vector<int>> adjList = g.getAdjList();
    int n = adjList.size();

    // Declaring structures
    vector<int> res;  // Result: stores traversal DFS
    stack<int> stack; // Stack for DFS

    // Initializing: all vertices as not visited
    vector<bool> visited(n, false); // Flag
    visited[v0] = true; // Initial vertex visited
    stack.push(v0);     // Add initial vertex

    // Iteration over the stack
    while (!stack.empty()) {

        // Get current vertex from the stack
        int curr = stack.top(); // Get current vertex
        stack.pop(); // Remove it from stack
        res.push_back(curr);  // Add at the transversal DFS

        // Explore non visited neighbors in reverse order
        vector<int> neighbors = adjList[curr];
        for (int i = neighbors.size() - 1; i >= 0; i--) {
            int neighbor = neighbors[i];
            if (!visited[neighbor]) { // not visited
                visited[neighbor] = true; // Visited
                stack.push(neighbor);     // Add to the stack
            }
        }
        // Using Iterators:
        // for (auto it = adjList[curr].rbegin(); it != adjList[curr].rend(); it++) {
        //     // iterating through adjacency list of curr un reverse order; LIFO
        //     if (!visited[*u]) {
        //         visited[*u] = true; // Visited
        //         stack.push(*u); // Add to the stack
        //     }
        // }
    }
    return res;
}