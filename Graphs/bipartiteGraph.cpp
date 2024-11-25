#include <queue>
#include <vector>
#include <iostream>

using namespace std;

bool usingDFS(int vertex, vector<vector<int>> &adj, vector<int> &visited){
    for (auto nNode : adj[vertex]) {
        if (visited[nNode] == -1) {
            if (visited[vertex] == 0) {
                visited[nNode] = 1;
                usingDFS(nNode, adj, visited);
            }
            else if (visited[vertex] == 1) {
                visited[nNode] = 0;
                usingDFS(nNode, adj, visited);
            }
        } 
        else if (visited[nNode] != -1 && visited[nNode] == visited[vertex]) {
            return false;
        }
    }

    return true;
}

bool usingBFS(int vertex, vector<vector<int>> &adj, vector<int> &visited){
    queue<int> q;
    q.push(vertex);

    while (!q.empty()) {
        int cNode = q.front();
        q.pop();

        for (auto nNode : adj[cNode]) {
            if (visited[nNode] == -1) {
                if (visited[cNode] == 0) {
                    visited[nNode] = 1;
                    q.push(nNode);
                }
                else if (visited[cNode] == 1) {
                    visited[nNode] = 0;
                    q.push(nNode);
                }
            } 
            else if (visited[nNode] != -1 && visited[nNode] == visited[cNode]) {
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(int V, vector<vector<int>> &adj, int startNode){
    int N = adj.size();

    vector<int> visited(N, -1);
    visited[startNode] = 0;

    for (int i = 0; i < N; i++) {
        // if(usingBFS(i, adj, visited) == false) {
        if(usingDFS(i, adj, visited) == false) {
            return false;
        }
    }

    return true;
}

int main() {
    // Graph Structure:
    // 0 - 1
    // |   |
    // 3 - 2

    // colors = {0, 1};

    int V = 4;
    vector<vector<int>> adj(V);
    int startNode = 0;
    
    // Adding edges (undirected)
    adj[0].push_back(1); adj[1].push_back(0); 
    adj[1].push_back(2); adj[2].push_back(1);  
    adj[2].push_back(3); adj[3].push_back(2);  
    adj[3].push_back(0); adj[0].push_back(3);
    // adj[3].push_back(1); adj[1].push_back(3);
    
    if(isBipartite(V, adj, startNode))
        cout << "true\n";
    else
        cout << "false\n";
    
    return 0;
}