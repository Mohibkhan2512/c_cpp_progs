#include <iostream>
#include <vector>
#include <map>

using namespace std;

// element repets for more than (N/2) in an array
// here N is the size of the array

int majorityElement_Moores_voting(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}

int majorityElement(vector<int> arr) {
    map<int, int> mp;

    int N = arr.size();

    for (int i = 0; i < N; i++) {
        mp[arr[i]] += 1;
        if (mp[arr[i]] > (N/2)) {
            return arr[i];
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}