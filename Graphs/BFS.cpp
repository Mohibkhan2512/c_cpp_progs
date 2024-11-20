#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS on the graph
void BFS(int startNode, vector<vector<int>> &graph){
    int visited[graph.size()+1];
    vector<int> BFS;
    
    for (int i = 0; i <= graph.size(); i++) {
        visited[i] = 0;
    }

    visited[startNode] = 1;

    queue<int> q;
    q.push(startNode);

    while (!q.empty()) {
        int node = q.front();
        BFS.push_back(node);
        q.pop();

        for (auto i : graph[node]) {
            if (visited[i] != 1){
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    cout << " BFS for current graph :>> ";
    for (auto i : BFS) {
        cout << i << " ";
    }

    cout << endl;
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

    cout << "BFS starting from node 0: ";
    BFS(0, graph); // Start BFS from node 0

    return 0;
}