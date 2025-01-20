


#include <bits/stdc++.h>
using namespace std;

int missingK(vector < int > arr, int nSize, int k) {
    int low = 0, high = nSize - 1;
    if (k < arr[low]) return k;
    if (k > arr[high] - nSize) return k + nSize;

    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = arr[mid] - mid - 1;

        if (missing <= k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    // ans = arr[high] + more;
    // more = k - missing at high;
    // missing at high = arr[high] - high - 1;
    // ans = arr[high] + k - arr[high] + high + 1;
    // ans = k + high + 1;
    // return k + high + 1;

    return arr[high] + k - (arr[high] - high - 1);
}

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}

