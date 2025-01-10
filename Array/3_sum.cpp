#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

void find3Numbers(vector<int> arr, int sum) {
    int n = arr.size();
    vector<vector<int>> ans;
    
    // Sort the elements
    sort(arr.begin(), arr.end());

    // Fix the first element one by one 
    // and find the other two elements
    for (int i = 0; i < n - 3; i++) {

        // To find the other two elements, start two index
        // variables from two corners of the array and move
        // them toward each other
        int l = i + 1;  // index of the first element
                        // in the remaining elements
        int r = n - 1;  // index of the last element

        while (l < r) {
            int curr_sum = arr[i] + arr[l] + arr[r];
            if (curr_sum == sum) {
                ans.push_back({arr[i] ,arr[l] ,arr[r]});
                break;
            } else if (curr_sum < sum)
                l++;
            else // curr_sum > sum
                r--;
        }
    }

    cout << "Pairs with expected sum :>> \n";

    for (auto it : ans) {
        for (auto it2 : it) {
            cout << it2 << " ";
        } 
        cout << "\n";
    }
}

int main()
{
    vector<int> arr = { 1, 4, 45, 6, 10, 8 };
    int sum = 22;
    find3Numbers(arr, sum);
    return 0;
}