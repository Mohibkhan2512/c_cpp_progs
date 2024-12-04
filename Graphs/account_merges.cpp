// Article link => https://takeuforward.org/data-structure/accounts-merge-dsu-g-50/

#include <bits/stdc++.h>
#include <string>
#include <sys/types.h>
#include <unordered_map>
#include <vector>
using namespace std;

//User function Template for C++
class DisjointSet {
    public:
        vector<int> size, parent;
        DisjointSet(int nSize) {
            size.resize(nSize + 1, 1);
            parent.resize(nSize+1);
            for (int i = 0; i <= nSize; i++) {
                parent[i] = i;
            }
        }

        int findUltimateParent(int cNode) {
            if (cNode == parent[cNode]) {
                return cNode;
            }
            return parent[cNode] = findUltimateParent(parent[cNode]);
        }

        void unionBySize(int u, int v) {
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);

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

class Solution{
    public:
        void accountsMerge(vector<vector<string>> accounts) {
            unordered_map<string, int> mp;
            vector<string> ans[accounts.size()];
            DisjointSet ds(accounts.size());

            for (int acIdx = 0; acIdx < accounts.size(); acIdx++) {
                for (int Idx = 1; Idx < accounts[acIdx].size(); Idx++) {
                    vector<string> tmp;
                    if (mp.find(accounts[acIdx][Idx]) == mp.end()) {
                        mp[accounts[acIdx][Idx]] = acIdx;
                    } 
                    else {
                        ds.unionBySize(mp[accounts[acIdx][Idx]], acIdx);
                    }

                }
            }

            // Iterate over the map and print each key-value pair
            for (const auto& pair : mp) {
                // cout << pair.first << ": " << pair.second << endl;
                string mail = pair.first;
                int node = pair.second;

                int ulp_node = ds.findUltimateParent(node);
                ans[ulp_node].push_back(mail);
            }

            cout << "Merged email lists for users :>> \n";
            int nameCnt = 0;
            for (auto acc : ans) {
                int size = acc.size();
                if (size > 0) {
                    cout << accounts[nameCnt][0] << ": ";
                    for (int i = 0; i < size; i++) {
                        cout << acc[i] << " ";
                    }
                    cout << endl;
                }
                nameCnt++;
            }
        }
};

int main() {

    vector<vector<string>> accounts = {
        {"John", "j1@com", "j2@com", "j3@com"},
        {"John", "j4@com"},
        {"Raj", "r1@com", "r2@com"},
        {"John", "j1@com", "j5@com"},
        {"Raj", "r2@com", "r3@com"},
        {"Mary", "m1@com"}
    };


    Solution obj;
    obj.accountsMerge(accounts);
    
    return 0;
}