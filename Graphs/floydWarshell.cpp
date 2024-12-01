#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	void shortest_distance(vector<vector<int>>&matrix) {
		int n = matrix.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == -1) {
					matrix[i][j] = 1e9;
				}
				if (i == j) matrix[i][j] = 0;
			}
		}

		for (int viaNode = 0; viaNode < n; viaNode++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = min(matrix[i][j],
					                   matrix[i][viaNode] + matrix[viaNode][j]);
				}
			}
		}

        // to check if negative weight cycle is present in the  graph
		for (int i = 0; i < n; i++) {
            if(matrix[i][i] < 0) cout << "Negative cycle present in graph";
        }
        
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 1e9) {
					matrix[i][j] = -1;
				}
			}
		}
	}
};


int main() {

	int V = 4;
	vector<vector<int>> matrix(V, vector<int>(V, -1));
	matrix[0][1] = 2;
	matrix[1][0] = 1;
	matrix[1][2] = 3;
	matrix[3][0] = 3;
	matrix[3][1] = 5;
	matrix[3][2] = 4;

	Solution obj;
	obj.shortest_distance(matrix);

	for (auto row : matrix) {
		for (auto cell : row) {
			cout << cell << "\t";
		}
		cout << endl;
	}

	return 0;
}