
#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

class Solution{
    private:
        void topoSort(int vertex, vector<pair<int, int>> graph[], vector<int> &visited, stack<int> &stk){
            visited[vertex] = 1;

            for (auto pNode : graph[vertex]) {
                int nNode = pNode.first;
                if (!visited[nNode]) {
                    topoSort(nNode, graph, visited, stk);
                }
            }

            stk.push(vertex);
        }
    public:
        vector<int> shortestPath(int nVertices, int nEdges, vector<vector<int>> edges){
            vector<int> shortestPath(nVertices, 1e9);
            vector<int> visited(nVertices, 0);
            stack<int> stk;

           vector<pair<int, int>> graph[nVertices];

            for (int i = 0; i < nEdges; i++) {
                int u = edges[i][0];
                int v = edges[i][1];
                int cost = edges[i][2];

                graph[u].push_back({v, cost});
            }

            for (int i = 0; i < nVertices; i++) {
                if (!visited[i]) {
                    topoSort(i, graph, visited, stk);
                }
            }

            int startNode = stk.top();
            shortestPath[startNode] = 0;

            while (!stk.empty()) {
                int cNode = stk.top();
                stk.pop();

                for (auto pNode : graph[cNode]) {
                    int nNode = pNode.first;
                    int cost = pNode.second;
    
                    shortestPath[nNode] = min(shortestPath[nNode], shortestPath[cNode] + cost);
                }
            }

            // puts("\n");

            for (int i = 0; i < nVertices; i++) {
                if (shortestPath[i] == 1e9) shortestPath[i] = -1;
            }

            return shortestPath;
        }
};


int main() {

  int N = 6, M = 7;
  
  vector<vector<int>> edges = {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
  Solution obj;
  vector < int > ans = obj.shortestPath(N, M, edges);

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  puts("\n");

  return 0;

}