#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

bool detectCycle(vector<int> adj[], vector<int>& visited, int node){
    visited[node] = 1;

    queue<pair<int, int> > q;
    q.push({node, -1});

    while (!q.empty()) {
        int curNode = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int nNode : adj[curNode]){
            if (!visited[nNode]) {
                visited[nNode] = 1;
                q.push({nNode, curNode});
            }
            else if (parent != nNode) {
                return true;
            }
        }
    }

    return false;
}

bool isCyclePresent(vector<int> adj[], int V){
    vector<int> visited(V, 0);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (detectCycle(adj, visited, i)) {
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
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);

    if (isCyclePresent(adj, V))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}