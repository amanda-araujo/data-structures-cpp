//
// Created by Amanda Araujo on 10/03/2025.
//
#include <iostream>
#include <map>
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
};

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

    // BFS: Breadth-First Search (Busca em Largura)

    // DFS: Deep-First Search (Busca em Profundidade)

    return 0;
}