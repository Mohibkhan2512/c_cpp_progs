#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int> dist(n, 1e9);

        int matrix[n][m];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(i == j)	matrix[i][j] = 0;
				else matrix[i][j] = 1e9;
			}
		}
		
		for(auto it : edges){
			matrix[it[0]][it[1]] = it[2];
			matrix[it[1]][it[0]] = it[2];
		}
		
		for(int via = 0; via < n; via++){
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
				}
			}
		}

		// for (int i = 0; i < n; i++) {
		// 	for (int j = 0; j < m; j++) {
		// 		cout << matrix[i][j] << " ";
		// 	}
		// 	cout << "\n";
		// }

		int minCityCnt = 1e9;
		int cityWithMinCnt = -1;

		for (int i = 0; i < n; i++) {
			int curCnt = 0;
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] <= distanceThreshold) {
					curCnt++;
				}
			}
			if (curCnt <= minCityCnt) {
				minCityCnt = curCnt;
				cityWithMinCnt = i;
			}
		}

		return cityWithMinCnt;
    }
};
int main() {

	int n = 4;
	int m = 4;
	vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
	int distanceThreshold = 4;

	Solution obj;
	int cityNo = obj.findCity(n, m, edges, distanceThreshold);
	cout << "The answer is node: " << cityNo << endl;

	return 0;
}