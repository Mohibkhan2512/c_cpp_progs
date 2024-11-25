#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool detectCycleUsingDFS(vector<int> adj[], vector<int>& visited, int curNode, int parentNode){
    visited[curNode] = 1;
    // printf("curNode: %d\n", curNode);
    for (auto nNode : adj[curNode]){
        // printf("nNode: %d\n", nNode);

        if (!visited[nNode]) {
            detectCycleUsingDFS(adj, visited, nNode, curNode);
        }
        else if (visited[nNode] && parentNode != nNode) {
            // puts("found cycle...");
            // cout << "p: " << parentNode << " n: " << nNode << endl;
            return true;
        }
    }

    return false;
}

bool isCyclePresent(vector<int> adj[], int V){
    vector<int> visited(V, 0);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (detectCycleUsingDFS(adj, visited, i, -1) == true) {
                return true;
            }
        }
    }

    return false;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    // addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);

    if (isCyclePresent(adj, V))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}