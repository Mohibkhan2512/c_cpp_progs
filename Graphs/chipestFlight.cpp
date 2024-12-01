#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution{
    public:
        int cheapestFlight(int V, vector<vector<int>> flights, int src, int dst, int allowedStops){
            vector<int> dist(V, 1e9);
            allowedStops++;

            vector<vector<int>> adj[V];

            for(auto it: flights){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                adj[u].push_back({v, wt});
            }

            queue<pair<int, pair<int, int>>> q;

            dist[src] = 0;

            q.push({0, {src, dist[src]}});

            while (!q.empty()) {
                int cStops = q.front().first;
                int cNode = q.front().second.first;
                int cDist = q.front().second.second;
                q.pop();

                for(auto pair : adj[cNode]){
                    int nNode = pair[0];
                    int nDist = pair[1];

                    if (cStops >= allowedStops) {
                        continue;
                    }
                    if (cDist + nDist < dist[nNode] && cStops <= allowedStops) {
                        dist[nNode] = cDist + nDist;
                        q.push({cStops+1, {nNode, dist[nNode]}});
                    }
                }

            }

            if (dist[dst] == 1e9) {
                return -1;
            }
            return dist[dst];
        }
};

int main()
{
    // Driver Code.
    int n = 4, src = 0, dst = 3, K = 1;

    vector<vector<int>> flights = {{0, 1, 100}, 
                                    {1, 2, 100}, 
                                    {2, 0, 100}, 
                                    {1, 3, 600},
                                    {2, 3, 200}};

    Solution obj;

    int ans = obj.cheapestFlight(n, flights, src, dst, K);

    cout << ans;
    cout << endl;

    return 0;
}