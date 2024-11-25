#include <vector>
#include <iostream>


using namespace std;

void DFS(vector<vector<char>>& graph, vector<vector<char>>& res, vector<vector<int>> visited, 
         int row, int col, int newClr, int initClr, vector<int> drow, vector<int> dcol){
    
    visited[row][col] = 1;
    res[row][col] = newClr;

    int n = graph.size();
    int m = graph[0].size();

    for (int i = 0; i < drow.size(); i++) {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if (nrow >= 0 && nrow < n && ncol >=0 && ncol < m && 
            !visited[nrow][ncol] && graph[nrow][ncol] == initClr && res[nrow][ncol] != newClr){
                DFS(graph, res, visited, nrow, ncol, newClr, initClr, drow, dcol);
            }
    }
    
}
void floodFill(vector<vector<char>>& graph, vector<vector<char>>& res, int x, int y, int newClr){
    int n = graph.size();
    int m = graph[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int initClr = res[x][y];

    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};

    DFS(graph, res, visited, x, y, newClr, initClr, drow, dcol);

}

int main() {
    vector<vector<char>> graph =  { {1, 1, 1}, 
                                    {1, 1, 0}, 
                                    {1, 0, 1} };

    vector<vector<char>> res = graph;

    int x = 1, y = 1, newClr = 3;

    floodFill(graph, res, x, y, newClr);

    // Print the 2D vector
    for (const auto row : res) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl; // Move to the next line after each row
    }

    return 0;
}