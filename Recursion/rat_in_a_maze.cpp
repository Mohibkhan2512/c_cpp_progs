#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Initialize a string direction which represents all the
// directions.
string direction = "DLRU";

// Arrays to represent change in rows and columns
int dr[4] = { 1, 0, 0, -1 };
int dc[4] = { 0, -1, 1, 0 };

// Function to check if cell(row, col) is inside the maze
// and unblocked
bool isValid(int row, int col, int n, vector<vector<int> >& visited, vector<vector<int> >& maze)
{
    return row >= 0 && col >= 0 && row < n && col < n
           && visited[row][col] == 0 && maze[row][col] == 1;
}

// Function to get all valid paths
void findPath(int row, int col, vector<vector<int> >& maze,
              int n, vector<string>& ans,
              string& currentPath, vector<vector<int>> &visited)
{
    // If we reach the bottom right cell of the matrix, add
    // the current path to ans and return
    if (row == n - 1 && col == n - 1) {
        ans.push_back(currentPath);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nRow = row+dr[i];
        int nCol = col+dc[i];
        if (isValid(nRow, nCol, n, visited, maze)) {
            visited[nRow][nCol] = 1;
            currentPath += direction[i];
            findPath(nRow, nCol, maze, n, ans, currentPath, visited);
            currentPath.pop_back();
            visited[nRow][nCol] = 0;
        }
    }
    
}

int main()
{
    vector<vector<int> > maze = { { 1, 0, 0, 0 },
                                  { 1, 1, 0, 1 },
                                  { 1, 1, 0, 0 },
                                  { 0, 1, 1, 1 } };

    int n = maze.size();
    vector<vector<int>> visited(n, vector<int> (n, 0));
    // vector to store all the valid paths
    vector<string> result;
    // Store current path
    string currentPath = "";

    if (maze[0][0] != 0 && maze[n - 1][n - 1] != 0) {
        // Function call to get all valid paths
        findPath(0, 0, maze, n, result, currentPath, visited);
    }

    if (result.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
    cout << endl;

    return 0;
}