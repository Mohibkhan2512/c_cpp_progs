// Article link => https://takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46/

#include <bits/stdc++.h>
#include <vector>

using namespace std;

class DisjointSet {
    private:
        vector<int> rank, parent, size;
    public:
        DisjointSet(int n) {
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1, 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }

        //Path compression
        int findUltimateParent(int node) {
            if (node == parent[node]) {
                return node;
            }
            return parent[node] = findUltimateParent(parent[node]);
        }

        void unionByRank(int u, int v) {
            int ulParent_u = findUltimateParent(u);
            int ulParent_v = findUltimateParent(v);

            if (ulParent_u == ulParent_v) {
                return;
            }

            if (rank[ulParent_u] < rank[ulParent_v]) {
                parent[ulParent_u] = ulParent_v;
            } 
            else if (rank[ulParent_v] < rank[ulParent_u]) {
                parent[ulParent_v] = ulParent_u;
            } 
            else{
                parent[ulParent_v] = ulParent_u;
                rank[ulParent_u]++;
            }
        }

        void unionBySize(int u, int v) {
            int ulParent_u = findUltimateParent(u);
            int ulParent_v = findUltimateParent(v);

            if (ulParent_u == ulParent_v) {
                return;
            }

            if (size[ulParent_u] < size[ulParent_v]) {
                parent[ulParent_u] = ulParent_v;
                size[ulParent_v] = size[ulParent_u] + size[ulParent_v];
            } 
            else{
                parent[ulParent_v] = ulParent_u;
                size[ulParent_u] = size[ulParent_u] + size[ulParent_v];
            }
        }
};

int main() {
    DisjointSet dsRank(7), dsSize(7);

    cout << "Union by Rank :>> \n";
    dsRank.unionByRank(1, 2);
    dsRank.unionByRank(2, 3);
    dsRank.unionByRank(4, 5);
    dsRank.unionByRank(6, 7);
    dsRank.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (dsRank.findUltimateParent(3) == dsRank.findUltimateParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    // after adding connecting edge for two components
    dsRank.unionByRank(3, 7);

    if (dsRank.findUltimateParent(3) == dsRank.findUltimateParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    cout << "Union by Size :>> \n";
    dsSize.unionBySize(1, 2);
    dsSize.unionBySize(2, 3);
    dsSize.unionBySize(4, 5);
    dsSize.unionBySize(6, 7);
    dsSize.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (dsSize.findUltimateParent(3) == dsSize.findUltimateParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    // after adding connecting edge for two components
    dsSize.unionBySize(3, 7);

    if (dsSize.findUltimateParent(3) == dsSize.findUltimateParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

}