
#include <bits/stdc++.h>
#include <cstdlib>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution{
    private:
        void topoSort(vector<int> orderGraph[], int size, vector<int> &tSorted){
            vector<int> indig(size, 0);

            for (int i = 0; i < size; i++) {
                for (auto nNode : orderGraph[i]) {
                    indig[nNode]++;
                }
            }

            queue<int> q;

            for (int i = 0; i < size; i++) {
                if (indig[i] == 0) {
                    q.push(i);
                }
            }

            while (!q.empty()) {
                int cNode = q.front();
                q.pop();
                tSorted.push_back(cNode);

                for (auto nNode : orderGraph[cNode]) {
                    indig[nNode]--;
                    if (indig[nNode] == 0) {
                        q.push(nNode);
                    }
                }
            }
        }

    public:
        string findOrder(string dict[], int N, int K){
            vector<int> orderGraph[K];
            string orderStr = "";
            vector<int> tSorted;
            
            for (int i = 0; i < N-1; i++) {
                string curWord = dict[i];
                string nextWord = dict[i+1];
                int minlen = min(curWord.size(), nextWord.size());

                for (int j = 0; j < minlen; j++) {
                    if (curWord[j] != nextWord[j]) {
                        int cIdx = (int)(curWord[j]) - (int)('a');
                        int nIdx = (int)(nextWord[j]) - (int)('a');
                        // cout << "Idx: " << cIdx << " " << nIdx << "\n";
                        orderGraph[cIdx].push_back(nIdx);
                        break;
                    }
                }

            }

            // for (int i = 0; i < K; i++) {
            //     for (auto it : orderGraph[i]) {
            //         cout << " " << it;
            //     }
            //     cout << "\n";
            // }

            topoSort(orderGraph, K, tSorted);

            // cout << "tsorted :>> ";
            for (int i = 0; i < tSorted.size(); i++) {
                // cout << char(tSorted[i] + 'a') << " ";
                orderStr += char(tSorted[i] + 'a');
            }

            return orderStr;
        }
};

int main() {

	int N = 5, K = 4;
	string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
	Solution obj;
	string ans = obj.findOrder(dict, N, K);

	for (auto ch : ans)
		cout << ch << ' ';
	cout << endl;

	return 0;
}