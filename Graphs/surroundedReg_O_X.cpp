#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void DFS(vector<vector<string> >& grid, vector<vector<int> > &visited, int row, int col){
    cout << "For neb O Found on border for " << row << " " << col << endl;
    visited[row][col] = 1;
    int N = grid.size();
    int M = grid[0].size();

    int delR[] = {-1, 0, 1, 0};
    int delC[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int nRow = row + delR[i];
        int nCol = col + delC[i];
        if (nRow >= 0 && nRow < N && nCol >= 0 && nCol < M && 
            !visited[nRow][nCol] && grid[nRow][nCol] == "O") {
            cout << "For neb O Found on border for " << row << " " << col << " " << nRow << " " << nCol << "\n";
            
            DFS(grid, visited, nRow, nCol);
        }
    }
}

vector<vector<string> > changeSurrounded_O_To_X(vector<vector<string> >& grid){
    int N = grid.size();
    int M = grid[0].size();

    vector<vector<int> > visited(M, vector<int>(N, 0));

    // First row and last row boundry check
    for (int j = 0; j < M; j++) {
        // cout << "j: >> " << j << endl;
        if (!visited[0][j] && grid[0][j] == "O") {
            cout << " O Found on border for " << 0 << " " << j << "\n";
            DFS(grid, visited, 0, j);
        }
        if (!visited[N-1][j] && grid[N-1][j] == "O") {
            cout << " O Found on border for " << N-1 << " " << j << "\n";
            DFS(grid, visited, N-1, j);
        }
    }

    // First col and last col boundry check
    for (int i = 0; i < N; i++) {
        // cout << "i: >> " << i << endl;
        if (!visited[i][0] && grid[i][0] == "O") {
            cout << " O Found on border for " << " " << i << " 0 "<< "\n";
            DFS(grid, visited, i, 0);
        }
        if (!visited[i][M-1] && grid[i][M-1] == "O") {
            cout << " O Found on border for " << " " << i << " " << M-1 << "\n";
            DFS(grid, visited, i, M-1);
        }
    }

    puts("Visited :>> ");
    for(auto i: visited){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}

    // Update the untouched "O" with "X"
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && grid[i][j] == "O") {
                grid[i][j] = "X";
            }
        }
    }

    return grid;
}


int main() {
    // vector<vector<string> > grid = {{"X","O","X"},{"O","X","O"},{"X","O","X"}};
    vector<vector<string> > grid = {{"X", "O", "X", "X", "X", "X"}, 
                                    {"X", "O", "X", "X", "O", "X"},
                                    {"X", "X", "X", "O", "O", "X"},
                                    {"O", "X", "X", "X", "X", "X"},
                                    {"X", "X", "X", "O", "X", "O"},
                                    {"O", "O", "X", "O", "O", "O"}};

    vector<vector<string> > res = changeSurrounded_O_To_X(grid);

    for(auto i: res){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}

    return 0;
}
