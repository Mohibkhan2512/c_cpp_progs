


#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    int low = 1, high = n/2, ans = -1;
    //Binary search on the answers:

    while (low <= high) {
        int mid = (low + high) / 2;

        if (mid * mid <= n) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
   
    return ans;
}

int main()
{
    int n = 28;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}

