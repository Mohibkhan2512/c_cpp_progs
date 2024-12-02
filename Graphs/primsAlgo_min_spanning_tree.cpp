#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
public:
    int minSpanningTree(int V, vector<vector<int>> adj[]){
        vector<int> visited(V, 0);

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int startNode = 0;
        visited[startNode] = 1;
        int edgeWeightOfMST = 0;
        vector<pair<int, int>> MST;

        pq.push({0, {startNode, -1}});

        while (!pq.empty()) {
            int cWt = pq.top().first;
            int cNode = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();

            if (visited[cNode] == 1 && cNode != startNode) continue;

            else if (visited[cNode] != 1) {
                visited[cNode] = 1;
                edgeWeightOfMST += cWt;
                MST.push_back({parent, cNode});
            }
            
            for (auto it : adj[cNode]) {
                    int nNode = it[0];
                    int nWt = it[1];
                if (visited[nNode] != 1) {
                    pq.push({nWt, {nNode, cNode}});
                }
            }
        }

        cout << "MST Edges :>> \n";
        for (auto it : MST) {
            cout << it.first << " -> " << it.second << endl;
        }

        return edgeWeightOfMST;
    }
};

int main() {

	int V = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	vector<vector<int>> adj[V];
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	Solution obj;
	int sum = obj.minSpanningTree(V, adj);
	cout << "\nThe sum of all the edge weights: " << sum << endl;

	return 0;
}