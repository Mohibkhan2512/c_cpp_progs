#include <algorithm>
#include<bits/stdc++.h>
#include <utility>

using namespace std;
// A structure to represent a job 
struct Job {
   int id; // Job Id 
   int deadline; // Deadline of job 
   int profit; // Profit if job is over before or on deadline 
};
class Solution {
   public:
      bool static descendingOrd(Job a, Job b) {
        return a.profit > b.profit;
      }

      pair<int, int> JobScheduling(Job arr[], int nSize) {
        int jobCnt = 0, maxProfit = 0;
        sort(arr, arr+nSize, descendingOrd);

        int maxDeadline = arr[0].deadline;

        for (int i = 1; i < nSize; i++) {
            maxDeadline = max(maxDeadline, arr[i].deadline);
        }

        int availableSlots[maxDeadline+1];

        for (int i = 0; i <= maxDeadline; i++) {
            availableSlots[i] = -1;
        }

        for (int i = 0; i < nSize; i++) {
            for (int j = arr[i].deadline; j >= 1; j--) {
                if (availableSlots[j] == -1) {
                    availableSlots[j] = arr[i].id;
                    jobCnt++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }

        return {jobCnt, maxProfit};
      }
};
int main() {
   int n = 4;
   Job arr[] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   //function call
   pair < int, int > ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;

   return 0;
} 