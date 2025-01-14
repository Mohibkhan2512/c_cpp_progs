// article link => https://takeuforward.org/arrays/minimum-days-to-make-m-bouquets/

#include <bits/stdc++.h>
#include <climits>
using namespace std;

bool possible(vector<int> &arr, int day, int m, int k) {
    int possibleBouquets = 0;
    int n = arr.size(), cnt = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] <= day) {
            cnt++;
        }
        else {
            possibleBouquets += (cnt/k);
            cnt = 0;
        }
    }
    possibleBouquets += (cnt/k);

    if (possibleBouquets >= m) {
        return true;
    }
    return false;
}
int roseGarden(vector<int> arr, int k, int m) {
    int minEle = INT_MAX, maxEle = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < minEle) {
            minEle = arr[i];
        }
        else if (arr[i] > maxEle) {
            maxEle = arr[i];
        }
    }

    int low = minEle, high = maxEle, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        bool possibleWithCurrentDay = possible(arr, mid, m, k);

        if (possibleWithCurrentDay) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = roseGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}