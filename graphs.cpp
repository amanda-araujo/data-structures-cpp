//
// Created by Amanda Araujo on 10/03/2025.
// Ref. https://www.geeksforgeeks.org/implementation-of-graph-in-cpp/
//

/* Graphs: non-linear data structures >> C++: classes!
 * Collection of vertices and edges
 * Implementation: 1) Adjacent Matrix 2) Adjacency List
 */

#include <iostream>
#include <vector>
#include <map>
#include <list>
using namespace std;

// Matrix: 2D Array C++
int arr[4][2] = {{11, 12}, {21, 22}, {31, 32}, {41, 42}};
vector<vector<int>> hotel = vector<vector<int>>(10, vector<int>(10, 0));
/* vector<int>(10, 0)    - Creates a vector of 10 int, all initialized to 0
 *                         represents a row of the matrix
 * vector<vector<int>>(10, ...)    - Creates 10 such rows, forming matrix n x n
 */


// Graph implementation: Adjacency Matrix
class Graph {
    // Declare structure: adjacency matrix to store edges
    vector<vector<int>> adj_matrix; // Attribute (private); 2D vector

    public:
        Graph(int n) { // Constructor (initialization)
            // Input: n - number of nodes
            adj_matrix = vector<vector<int>>(n, vector<int>(n, 0));
        }

        // Methods:
        void addEdge(int u, int v) {
            // Input: vertice u and vertice v
            // Outcome: Add an edge between vertices 'u' and 'v'
            adj_matrix[u][v] = 1; // u -> v
            adj_matrix[v][u] = 1; // undirected graph (u -> v = v -> u)
        }

        void printAdjMatrix() {
            // Outcome: Print the representation
            cout << "Graph: Adjacency Matrix" << endl;
            int n = adj_matrix.size(); // Number of vertices
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << adj_matrix[i][j] << " ";
                }
                cout << endl; // end of row
            }
        }
};

// 2) Adjacency List: vertices to lists of edges
/* Space efficient (~|V|)
 * Adjacency List >> Map (!); Stores only the edges
 */
// Graph implementation: Adjacency List
class GraphAdjList {
    // Declare structure: map (Key: vertice | Value: list of edges)
    map<int, list<int>> adj_list; // Attribute (private); Node, linked list

public:
    // GraphAdjList(int n) { // Constructor (initialization)
    //     // Initialization: n keys, value to be defined
    //     // adj_list.insert(make_pair(0, list<int>(n, -1)));
    //     // NOT NEEDED: Just as it [the pairs, edges] comes
    // } // Spare memory

    //Methods
    void addEdge(int u, int v) {
        // Input: vertice u and vertice v
        // Outcome: Add an edge between vertices 'u' and 'v'
        adj_list[u].push_back(v);
        adj_list[v].push_back(u); // undirected

        /* Way of thinking: add 'u' as key
         * adj_list[u]: returns the list of neighbors for node 'u' (linked list)
         * push_back(v): adds 'v' to that list
         */
    }
    void printAdjList() {
        // Outcome: Print the representation
        // Iterate over each vertex
        cout << "Graph: Adjacency List" << endl;
        for (auto i : adj_list) {
            cout << i.first << " -> ";    // Print the vertex
            for (auto j : i.second) { // Linked list
                cout << j << " "; // Print the connected vertex
            }
            cout << endl; // end of vertex
        }
    }
};



int main () {
    // Create graphs
    Graph g(5); // 5 vertices
    GraphAdjList G;

    // Adding edges (0, 1), (0, 2), (1, 3), (1, 4), (2, 3)
    g.addEdge(0,1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 3);
    G.addEdge(1, 4);
    G.addEdge(2, 3);

    // Print graph
    g.printAdjMatrix();
    G.printAdjList();

    return 0;
}

/* Adjacency Matrix
 * Time complexity: O(|V|^2)
 * Suitable for dense graphs
 *
 * Adjacency List
 * Time complexity: O(|V| + |E|)
 * Efficient (space) for sparse graphs
 * Suitable for sparse graphs
*/