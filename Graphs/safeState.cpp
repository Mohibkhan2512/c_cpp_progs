#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool usingDFS(int vertex, vector<int> adj[], vector<int>& visited, vector<int>& curPath){
    visited[vertex] = 1;
    curPath[vertex] = 1;

    for (auto nNode : adj[vertex]) {
        if (!visited[nNode]) {
            if (usingDFS(nNode, adj, visited, curPath) == true) {
                return true;
            }
        }
        else if (curPath[nNode]) {
            return true;
        }
    }

    curPath[vertex] = 0;
    return false;
}


bool safeNodesInGraph(int V, vector<int> adj[]){
    vector<int> visited(V, 0);
    vector<int> curPath(V, 0);
    vector<int> safeNodes(V, 0);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            usingDFS(i, adj, visited, curPath);
        }
    }

    // cout << "\ncurPath :>> ";
    // for (int i = 0; i < V; i++) {
    //     cout << " " << curPath[i];
    // }

    int totalSafeNodes = 0;
    for (int i = 0; i < V; i++) {
        if (!curPath[i]) {
            totalSafeNodes++;
            safeNodes[i] = i;
        }
    }

    if (totalSafeNodes != 0) {
        cout << "\nSafe Nodes :>> ";
        for (int i = 0; i < V; i++) {
            safeNodes[i] != 0 ? cout << " " << safeNodes[i] : cout << "";
        }
        return true;
    }

    return false;
}

int main() {

	// V = 11, E = 11;
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	bool ans = safeNodesInGraph(V, adj);

	if (ans)
		cout << "\nTrue\n";
	else
		cout << "\nFalse\n";
    
    

	return 0;
}