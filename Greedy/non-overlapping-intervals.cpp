#include<iostream> 
#include<bits/stdc++.h> 
using namespace std; 
//comparator function for sorting based on endpoints 
bool cmp(vector<int>& a, vector<int>& b) {return a[1] < b[1];} 
 
int eraseOverlapIntervals(vector<vector<int>>& intervals) { 
    sort(intervals.begin(), intervals.end(),cmp); 
    
    int ans, cantBeMerged = 1; 
    int start = intervals[0][0], end = intervals[0][1]; 
    for(int i = 1; i < intervals.size(); i++){ 
        if (intervals[i][0] >= end) {
            // if start time for current interval >= end time 
            // of last interval. we can't merge them together
            cantBeMerged++;
            end = intervals[i][1];
        }
    } 
    // can be merged = [ total - can't be merged ]
    return ans = intervals.size() - cantBeMerged; 
 } 
int main() { 
    vector<vector<int>>intervals; 
    intervals.push_back({1,100}); 
    intervals.push_back({1,11}); 
    intervals.push_back({11,22}); 
    intervals.push_back({2,12}); 
    cout << eraseOverlapIntervals(intervals) << endl; 
    return 0; 
} 