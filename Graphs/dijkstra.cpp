#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> shortestPath(V, 1e9);

        pq.push({0, S});
        shortestPath[S] = 0;

        while (!pq.empty()) {
            int cost = pq.top().first;
            int cNode = pq.top().second;
            pq.pop();

            for (auto pair : adj[cNode]) {
                int nNode = pair[0];
                int nCost = pair[1];
                if (shortestPath[cNode] + nCost < shortestPath[nNode]) {
                    shortestPath[nNode] = shortestPath[cNode] + nCost;
                    pq.push({shortestPath[nNode], nNode});
                }
            }
        }

        return shortestPath;
    }

};

int main()
{
    // Driver code.
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}