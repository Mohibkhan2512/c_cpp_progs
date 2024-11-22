#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

void BFS(int srow, int scol, vector<vector<char>>& graph, vector<vector<int>>& visited){
    visited[srow][scol] = 1;
    int n = graph.size();
    int m = graph[0].size();

    queue<pair<int, int>> q;
    q.push({srow, scol});

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int drow = -1;  drow <= 1; drow++) {
            for (int dcol = -1; dcol <= 1; dcol++) {
                if (i+drow >= 0 && i+drow < n && j+dcol >= 0 && j+dcol < m 
                    && !visited[i+drow][j+dcol] && graph[i+drow][j+dcol] == '1') {
                        visited[i+drow][j+dcol] = 1;
                        q.push({i+drow, j+dcol});
                }
            }
        }
    }

}

int numOfIslands(vector<vector<char>>& graph){
    int n = graph.size();
    int m = graph[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && graph[i][j] == '1') {
                visited[i][j] = 1;
                cnt++;
                BFS(i, j, graph, visited);
            }
        }
    }
    return cnt;
}


int main() {
    vector<vector<char>> graph = {  { '1', '1', '0', '0', '0' },
                                    { '0', '1', '0', '0', '1' },
                                    { '1', '0', '0', '1', '1' },
                                    { '0', '0', '0', '0', '0' },
                                    { '1', '0', '1', '1', '0' } };

    cout << "Number of Islands: " << numOfIslands(graph) << endl;

    return 0;
}