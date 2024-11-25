
#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <string>

using namespace std;

void BFS(int row, int col, vector<vector<int> > grid, vector<vector<int> >& visited){
    visited[row][col] = 1;
    queue<pair<int, int> > q;
    q.push({row, col});

    int N = grid.size();
    int M = grid[0].size();
    
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    int delSize = sizeof(delRow) / sizeof(delRow[0]);

    while (!q.empty()) {
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop();

        for (int i = 0; i < delSize; i++) {
            int nRow = curRow + delRow[i];
            int nCol = curCol + delCol[i];

            if (nRow >= 0 && nRow < N && nCol >= 0 && nCol < M &&
                !visited[nRow][nCol] && grid[nRow][nCol] == 1) {
                    q.push({nRow, nCol});
                    visited[nRow][nCol] = 1;
            }
        }
    }
}

int numOfEnclaves(vector<vector<int> > grid){
    int N = grid.size();
    int M = grid[0].size();

    vector<vector<int> > visited(N, vector<int>(M, 0));

    // Check for 1's in first row and last row
    for (int j = 0; j < M; j++) {
        if (!visited[0][j] && grid[0][j] == 1) {
            BFS(0, j, grid, visited);
        }
        if (!visited[N-1][j] && grid[N-1][j] == 1) {
            BFS(N-1, j, grid, visited);
        }
    }

    // Check for 1's in first col and last col
    for (int i = 0; i < N; i++) {
        if (!visited[i][0] && grid[i][0]) {
            BFS(i, 0, grid, visited);
        }
        if (!visited[i][M-1] && grid[i][M-1]) {
            BFS(i, M-1, grid, visited);
        }
    }
    int totalEnclaves = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                totalEnclaves++;
            }
        }
    }

    puts("Visited :>> ");
    for(auto i: grid){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}

    return  totalEnclaves;
}

int main(){
    vector<vector<int> > grid = {{0, 0, 0, 1},
                                {0, 1, 1, 0},
                                {0, 1, 1, 0},
                                {0, 0, 0, 1},
                                {0, 1, 1, 0}};
    
    cout << "Total number of Enclaves :>> " << numOfEnclaves(grid) << "\n";
    
    return 0;
}