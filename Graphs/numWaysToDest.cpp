#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution{
    public:
        int countPaths(int V, vector<vector<int>> edges){
            vector< pair<int, int> > adj[V];
            vector<int> dist(V, 1e9);
            vector<int> ways(V, 0);

            for(auto it: edges){
                adj[it[0]].push_back({it[1], it[2]});
                adj[it[1]].push_back({it[0], it[2]});
            }

            priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

            int startNode = 0;
            int endNode = V-1;
            dist[startNode] = 0;
            ways[startNode] = 1;
            pq.push({0, startNode});

            while (!pq.empty()) {
                int cNode = pq.top().second;
                int cDist = pq.top().first;
                pq.pop();

                for(auto it : adj[cNode]){
                    int nNode = it.first;
                    int nDist = it.second;

                    if (cDist + nDist <= dist[nNode]) {
                        if (dist[nNode] == cDist + nDist) {
                            ways[nNode] = ways[nNode]+ways[cNode];
                        }
                        else{
                            dist[nNode] = cDist + nDist;
                            ways[nNode] = ways[cNode];
                            pq.push({dist[nNode], nNode});
                        }
                    }
                }
            }

            if (dist[endNode] == 1e9) {
                return -1;
            }

            return ways[endNode];
        }
};

int main()
{
    // Driver Code.
    int n = 7;

    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, 
    {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    Solution obj;

    int ans = obj.countPaths(n, edges);

    cout << ans;
    cout << endl;

    return 0;
}