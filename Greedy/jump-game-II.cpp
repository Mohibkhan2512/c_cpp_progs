                            
#include <vector>   
#include <algorithm>
#include <iostream>

using namespace std;

// Function to determine if
// you can reach the last index
int minJumps(vector<int>& nums) {
    int pLeftRange = 0, pRightRange = 0;
    int n = nums.size();
    int jumps = 0;

    while (pRightRange < n-1) {
        int canMaxJumpTill = 0;

        for (int i = pLeftRange; i <= pRightRange; i++) {
            canMaxJumpTill = max(canMaxJumpTill, i+nums[i]);
        }

        pLeftRange = pRightRange+1;
        pRightRange = canMaxJumpTill;
        jumps++;
    }

    return jumps;
}

int main() {
    vector<int> nums = {4, 3, 7, 1, 2};
    
    cout << "Array representing maximum jump from each index: ";
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    
    int ans = minJumps(nums);
    
    if (ans) {
        cout << "It is possible to reach the last index in jumps :>> " << ans << endl;
    } 
    
    return 0;
}
                            
                        