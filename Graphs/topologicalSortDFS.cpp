#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

void DFS(int node, vector<int> adj[], stack<int>& stk, vector<int> &visited, vector<int> &topSort){
    stk.push(node);
    visited[node] = 1;

    while (!stk.empty()) {
        int cNode = stk.top();
        cout << " " << cNode;
        topSort.push_back(cNode);
        stk.pop();

        for (auto nNode : adj[cNode]) {
            if (!visited[nNode]) {
                visited[nNode] = 1;
                stk.push(nNode);
            }
        }
    }
}

void topologicalSortUsingDFS(int V, vector<int> adj[], vector<int> &topSort){
    vector<int> visited(V, 0);

    stack<int> stk;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(i, adj, stk, visited, topSort);
        }
    }
}

int main(){
    vector<int> adj[] = {{}, {3}, {3}, {}, {0,1}, {0,2}};
    int V = sizeof(adj)/sizeof(adj[0]);

    vector<int> topSort;

    topologicalSortUsingDFS(V, adj, topSort);


    cout << "Topological sort :>> ";
    for (int i = topSort.size()-1; i >= 0; i--) {
        cout << " " << topSort[i];
    }
    cout << endl;
}