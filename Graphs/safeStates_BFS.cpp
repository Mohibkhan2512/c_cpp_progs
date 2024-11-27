#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> safeNodesInGraphBFS(int V, vector<int> adj[]) {
    // The reason for using rev of cur graph state is, (i.e., i->j to j->i)
    // after reverse if j is terminal node we should be able to reduce the indig for 
    // all nNodes to 0 (find topo sort) and the nodes for whom indig != 0 at 
    // the end of traversal must have a cycle, hence they can't be safe nodes.

    vector<int> adjRev[V];
    vector<int> indigree(V, 0);

    for (int i = 0; i < V; i++) {
        for (auto nNode : adj[i]) {
            adjRev[nNode].push_back(i);
            indigree[i]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indigree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> safeStates;
    while (!q.empty()) {
        int cNode = q.front();
        q.pop();
        safeStates.push_back(cNode);

        for (auto nNode : adjRev[cNode]) {
            indigree[nNode]--;
            if (indigree[nNode] == 0) {
                q.push(nNode);
            }
        }
    }

    sort(safeStates.begin(), safeStates.end());
    
    return safeStates;
}

int main() {

	// V = 11, E = 11;
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	vector<int> safeStatesOp = safeNodesInGraphBFS(V, adj);

    cout << "Safe States :>> ";
    for (auto it : safeStatesOp) {
        cout << " " << it;
    }
    
    puts("\n");
	return 0;
}