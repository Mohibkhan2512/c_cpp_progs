


#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); //size of array
    int toBePlacedCows = cows;
    int lastCowPlacedAt = stalls[0];

    for (int curIdx = 1; curIdx < n; curIdx++) {
        if (stalls[curIdx] - lastCowPlacedAt >= dist) {
            toBePlacedCows--;
            lastCowPlacedAt = stalls[curIdx];
            if (toBePlacedCows == 0) {
                cout << "Possible for dist :>> " << dist << "\n";
                return true;
            }
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size(); //size of array
    //sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}

