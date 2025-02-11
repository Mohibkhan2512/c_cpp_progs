                            
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// To calculate the maximum score obtainable
// by taking exactly 'k' cards from either
// the beginning or the end of the row
int maxScore(vector<int>& cardPoints, int k) {
    // Initialize left sum (lsum)
    // and right sum (rsum) to 0.
    int lsum = 0;
    int rsum = 0;
    
    // Initialize the
    // maximum sum (maxSum) to 0.
    int maxSum = 0;
    
    // Set rIndex to the index of 
    // he last element in cardPoints.
    int rIndex = cardPoints.size() - 1;
    
    // Calculate the sum of the first k
    // elements from the left side of the array.
    for(int i = 0; i < k; i++) {
        lsum += cardPoints[i];
    }
    
    // Initialize maxSum to the sum of
    // the first k elements from the left.
    maxSum = lsum;
    
    // Move one element from the
    // left to the right at a time.
    for(int i = k - 1; i >= 0; i--) {
        // Subtract the current element from
        // lsum as it's moved to the right.
        lsum = lsum - cardPoints[i];
        
        // Add the current right
        // element to rsum.
        rsum = rsum + cardPoints[rIndex];
        
        // Decrease the right index to point
        // to the next element on the left.
        rIndex = rIndex - 1;
        
        // Update maxSum to the maximum value
        // between the current maxSum and
        // the sum of lsum and rsum.
        maxSum = max(maxSum, lsum + rsum);
    }
    
    // Return the maximum sum obtained.
    return maxSum;
}




int main() {
    vector<int> arr = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    int k = 4;
    
    cout << "Given cards: ";
    for(int &card: arr){
        cout << card << " ";
    }
    cout << endl;
    cout << "Number of cards to pick: "<< k << endl;
    
    int result = maxScore(arr, k);
    
    cout << "Maximum score: " << result << endl;
    
    return 0;
}
                            
                        