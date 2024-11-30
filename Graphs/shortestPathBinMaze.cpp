#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
    public:
        int shortestPathinBinMaze(vector<vector<int>> grid, pair<int, int> source, pair<int, int> dest){
            // Edge Case: if the source is only the destination.
            if (source.first == dest.first &&
                source.second == dest.second)
                return 0;

            queue<pair<int, pair<int, int>>> q;

            int n = grid.size();
            int m = grid[0].size();

            vector<vector<int>> dist(n, vector<int>(m, 1e9));
            dist[source.first][source.second] = 0;

            q.push({0, {source.first, source.second}});

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            int delSize = sizeof(delRow)/sizeof(delRow[0]);

            while (!q.empty()) {
                int cNodeR = q.front().second.first;
                int cNodeC = q.front().second.second;
                int cNodeDist = q.front().first;
                q.pop();

                for (int i = 0; i < delSize; i++) {
                    int nNodeR = cNodeR + delRow[i];
                    int nNodeC = cNodeC + delCol[i];

                    if (nNodeR >= 0 && nNodeR < n && nNodeC >= 0 && nNodeC < m &&
                        cNodeDist + 1 < dist[nNodeR][nNodeC]) {
                            if (nNodeR == source.first && nNodeC == source.second) {
                                return cNodeDist + 1;
                            }
                            dist[nNodeR][nNodeC] = cNodeDist + 1;
                            q.push({dist[nNodeR][nNodeC], {nNodeR, nNodeC}});
                    }
                }
            }

            if (dist[dest.first][dest.second] != 1e9) {
                return dist[dest.first][dest.second];
            }

            return -1;
        }
};

int main()
{
    // Driver Code.

    pair<int, int> source, destination;
    source.first = 0;
    source.second = 1;
    destination.first = 2;
    destination.second = 2;

    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};

    Solution obj;

    int res = obj.shortestPathinBinMaze(grid, source, destination);

    cout << res;
    cout << endl;

    return 0;
}