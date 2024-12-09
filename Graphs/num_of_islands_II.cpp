// Article link => https://takeuforward.org/graph/number-of-islands-ii-online-queries-dsu-g-51/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

// User function Template for C++
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
    public:
        vector<int> numOfIslands(int n, int m, vector<vector<int>> operators) {
            DisjointSet ds(n * m);
            vector<vector<int>> visited(n, vector<int>(m, 0));

            vector<int> ans;
            int curCntOfIslands = 0;

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            int delSize = sizeof(delRow)/sizeof(delRow[0]);

            for (auto it : operators) {
                int cRow = it[0];
                int cCol = it[1];

                if (visited[cRow][cCol] == 0) {
                    visited[cRow][cCol] = 1;
                    curCntOfIslands++;

                    for (int i = 0; i < delSize; i++) {
                        int nRow = cRow + delRow[i];
                        int nCol = cCol + delCol[i];
                        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m) {
                            if (visited[nRow][nCol] == 1 && 
                                ds.findUPar(((cRow*m) + cCol)) != ds.findUPar(((nRow*m) + nCol))) {
                                ds.unionBySize((cRow*m) + cCol, (nRow*m) + nCol);
                                curCntOfIslands--;
                            }
                        }
                    }
                }
                // cout << cRow << " " << cCol << " " << curCntOfIslands << endl;
                ans.push_back(curCntOfIslands);
            }

            return ans;
        }
};

int main() {
    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}
    };

    Solution obj;
    vector<int> ans = obj.numOfIslands(n, m, operators);
    for (auto res : ans) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}