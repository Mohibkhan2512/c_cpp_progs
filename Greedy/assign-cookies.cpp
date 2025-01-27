                            
#include <vector>   
#include <algorithm>
#include <iostream>

using namespace std;

// Function to find the maximum
// number of content children
int findContentChildren(vector<int>& greed, vector<int>& cookieSize) {
    int nChilds = greed.size();
    int nCookies = cookieSize.size();

    sort(greed.begin(), greed.end());
    sort(cookieSize.begin(), cookieSize.end());

    int childIdx = 0, cookieIdx = 0;

    while (childIdx < nChilds && cookieIdx < nCookies) {
        if (greed[childIdx] <= cookieSize[cookieIdx]) {
            childIdx++;
        }
        cookieIdx++;
    }

    return childIdx;
}


int main() {
    vector<int> greed = {1, 5, 3, 3, 4};
    vector<int> cookieSize = {4, 2, 1, 2, 1, 3};
    
    cout << "Array Representing Greed: ";
    for(int i = 0; i < greed.size(); i++){
        cout << greed[i] << " ";
    }
    cout << endl;
    cout << "Array Representing Cookie Size: ";
    for(int i = 0; i < cookieSize.size(); i++){
        cout << cookieSize[i] << " ";
    }
    
    int ans = findContentChildren(greed, cookieSize);
    
    cout << endl << "No. of kids assigned cookies "<< ans;
    cout << endl;

    return 0;
}
                            
                        