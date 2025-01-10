#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals_striver(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

vector<vector<int>> mergeOverlappingIntervals_updated_with_back(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    int lowerBand= INT_MAX, upperBand = INT_MIN;

    for (auto pair : arr) {
        if (pair[0] < upperBand) {
            if (upperBand < pair[1]) {
                upperBand = pair[1];
                ans.back()[1] = upperBand;
            }
        } 
        else if (ans.empty() || pair[0] > upperBand) {
            lowerBand = pair[0];
            upperBand = pair[1];
            ans.push_back({lowerBand, upperBand});
        }
    }
    return ans;
}


vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;
    int lowerBand = arr[0][0], upperBand = arr[0][1];

    for (auto pair : arr) {
        if (pair[0] < upperBand) {
            upperBand = pair[1];
        } 
        else if (pair[0] > upperBand) {
            ans.push_back({lowerBand, upperBand});
            lowerBand = pair[0];
            upperBand = pair[1];
        }
    }
    ans.push_back({lowerBand,upperBand});
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals_updated_with_back(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}