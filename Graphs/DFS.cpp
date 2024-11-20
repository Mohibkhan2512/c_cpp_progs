#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS recursively
void DFS(int node, vector<bool>& visited, const vector<vector<int>>& graph) {
    // Mark the current node as visited
    visited[node] = true;
    cout << node << " "; // Process the current node

    // Recur for all the vertices adjacent to this vertex
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, visited, graph); // Recursive call
        }
    }
}

int main() {
    // Create a graph using an adjacency list
    vector<vector<int>> graph = {
        {1, 2},    // Neighbors of node 0
        {0, 3, 4}, // Neighbors of node 1
        {0, 4},    // Neighbors of node 2
        {1},       // Neighbors of node 3
        {1, 2}     // Neighbors of node 4
    };

    vector<bool> visited(graph.size(), false); 

    cout << "DFS starting from node 0: ";
    DFS(0, visited, graph); // Start DFS from node 0
    printf("\n");

    return 0;
}