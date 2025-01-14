#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); //size of the array.

    if (n == 1) {
        return arr[0];
    }
    else if (arr[0] != arr[1]) {
        return arr[0];
    }
    else if (arr[n-2] != arr[n-1]) {
        return arr[n-1];
    }

    int low = 1, high = n-2, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        // if arr[mid] is the single element:
        if (arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) {
            return arr[mid];
        }

        // we are in the left part of array (even, odd)
        // element is in right part
        if (arr[mid] % 2 == 1 && arr[mid] == arr[mid-1] ||
            arr[mid] % 2 == 0 && arr[mid] == arr[mid+1]) {
                //elemenate left part
                low = mid + 1;
        }
        // we are in the right part of array (odd, even)
        // element is in left part
        else {
            //elemenate right part
            high = mid - 1;
        }
    }

    // dummy return statement:
    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = singleNonDuplicate(arr);
    cout << "The single element is: " << ans << "\n";
    return 0;
}
