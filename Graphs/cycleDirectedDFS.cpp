#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
private:
	bool dfsCheck(int node, vector<int> adj[], vector<int> vis, vector<int> curPath) {
		vis[node] = 1;
		curPath[node] = 1;

		// traverse for adjacent nodes
		for (auto it : adj[node]) {
			// when the node is not visited
			if (!vis[it]) {
				if (dfsCheck(it, adj, vis, curPath) == true)
					return true;
			}
			// if the node has been previously visited
			// And it is already present in current path
			else if (curPath[it]) {
				return true;
			}
		}

		curPath[node] = 0;
		return false;
	}
public:
	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
		vector<int> vis(V, 0);
		vector<int> curPath(V, 0);

		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				if (dfsCheck(i, adj, vis, curPath) == true) return true;
			}
		}
		return false;
	}
};


int main() {

	// V = 11, E = 11;
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}