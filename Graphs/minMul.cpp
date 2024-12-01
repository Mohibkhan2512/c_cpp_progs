#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution{
    public:
        int minimumMultiplications(vector<int> arr, int start, int end){
            int mod = 100000;
            vector<int> dist(mod, 1e9);
            dist[start] = 0;

            queue<pair<int, int>> q;
            q.push({start, 0});

            while (!q.empty()) {
                int cNum = q.front().first;
                int steps = q.front().second;
                q.pop();

                for (int i = 0; i < arr.size(); i++) {
                    int num = (arr[i] * cNum) % mod;
                    if (num == end) {
                        return steps+1;
                    }
                    if (steps+1 < dist[num]) {
                        dist[num] = steps+1;
                        q.push({num, steps+1});
                    }
                }
            }

            return -1;
        }
};

int main()
{
    // Driver Code.
    int start = 3, end = 30;

    vector<int> arr = {2, 5, 7};

    Solution obj;

    int ans = obj.minimumMultiplications(arr, start, end);

    cout << ans;
    cout << endl;

    return 0;
}