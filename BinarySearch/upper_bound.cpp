
#include <bits/stdc++.h>
using namespace std;

// smallest number > target, return num index
int upperBound(vector<int>& nums, int target, int upperBoundIdx) {
    int n = nums.size();
    int low = 0, high = n-1, mid;

    while (low <= high) {
        mid = (low+high)/2;
        if (nums[mid] > target) {
            high = mid - 1;
            upperBoundIdx = mid;
        }
        else {
            low = mid + 1;
        }
    }

    return upperBoundIdx;
}


int main()
{
    vector<int> a = {3, 5, 8, 15, 19};;
    int target = 9;
    int ans = a.size();
    int ind = upperBound(a, target, ans);
    
    cout << "upperBound :>> " << ind << endl;
    return 0;
}


