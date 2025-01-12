
#include <bits/stdc++.h>
using namespace std;

// smallest number >= target, return num index
int lowerBound(vector<int>& nums, int target, int lowerBoundIdx) {
    int n = nums.size();
    int low = 0, high = n-1, mid;

    while (low <= high) {
        mid = (low+high)/2;
        if (nums[mid] >= target) {
            high = mid - 1;
            lowerBoundIdx = mid;
        }
        else {
            low = mid + 1;
        }
    }

    return lowerBoundIdx;
}


int main()
{
    vector<int> a = {3, 5, 8, 15, 19};;
    int target = 9;
    int ans = a.size();
    int ind = lowerBound(a, target, ans);
    
    cout << "lowerBound :>> " << ind << endl;
    return 0;
}


