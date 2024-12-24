#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int longestSuccessiveElements_optimal(vector<int> &a) {
    unordered_set<int> st;

    for (int i = 0; i < a.size(); i++) {
        st.insert(a[i]);
    }

    int longest = 1;
    int curLongest = 1;

    for (auto it : st) {
        if (st.find(it-1) == st.end()) {
            curLongest = 1;
            int x = it;
            while (st.find(x+1) != st.end()) {
                x++;
                curLongest++;
            }  
            longest = max(curLongest, longest);          
        }
    }

    return longest;
}

int longestSuccessiveElements(vector<int> &a) {
    sort(a.begin(),a.end());

    int longest = 1;
    int prev = a[0];
    int curLongest = 1;

    for (int i = 1; i < a.size(); i++) {
        if (a[i]-prev == 1) {
            curLongest++;
            prev = a[i];
        } 
        else if (a[i]-prev > 1) {
            prev = a[i];
            curLongest = 1;
        }

        longest = max(curLongest, longest);
    }
    return longest;

}

int main()
{
    vector<int> a = {100, 101, 102, 200, 1, 1, 2, 3, 4};
    int ans = longestSuccessiveElements_optimal(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}