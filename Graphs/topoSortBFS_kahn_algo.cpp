#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;


void topologicalSortUsingBFS(int V, vector<int> adj[], vector<int> &topSort){
    vector<int> indigree(V, 0);

    queue<int> q;

    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indigree[it]++;
        }
    }

    for (int i = 0; i < V; i++) {
        if (indigree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cNode = q.front();
        q.pop();
        topSort.push_back(cNode);

        for (auto nNode : adj[cNode]) {
            indigree[nNode]--;
            if (indigree[nNode] == 0) {
                q.push(nNode);
            }
        }
    }
}

int main(){
    vector<int> adj[] = {{}, {3}, {3}, {}, {0,1}, {0,2}};
    int V = sizeof(adj)/sizeof(adj[0]);

    vector<int> topSort;

    topologicalSortUsingBFS(V, adj, topSort);


    cout << "Topological sort :>> ";
    for (int i = 0; i < topSort.size(); i++) {
        cout << " " << topSort[i];
    }
    cout << endl;
}