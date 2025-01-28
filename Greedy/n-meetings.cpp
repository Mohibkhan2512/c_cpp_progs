//https://takeuforward.org/data-structure/n-meetings-in-one-room/
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct meeting {
   int start;
   int end;
   int pos;
};

class Solution {
   public:
        bool static comparator(struct meeting m1, meeting m2) {
            if (m1.end < m2.end) return true;
            else if (m1.end > m2.end) return false;
            else if (m1.pos < m2.pos) return true; // if end time is same
            return false;
        }

        void maxMeetings(int s[], int e[], int n) {
            meeting arr[n];

            for (int i = 0; i < n; i++) {
                arr[i].start = s[i];
                arr[i].end = e[i];
                arr[i].pos = i+1;
            }

            sort(arr, arr+n, comparator);

            vector<int> canBeArrangedMeetings;
            int maxMeetingsCnt = 1; // first meeting always possible
            int lastMeetingEndTime = arr[0].end;
            canBeArrangedMeetings.push_back(arr[0].pos);

            for (int i = 1; i < n; i++) {
                if (lastMeetingEndTime < arr[i].start) {
                    lastMeetingEndTime = arr[i].end;
                    maxMeetingsCnt++;
                    canBeArrangedMeetings.push_back(arr[i].pos);
                }
            }

            cout << "Maximum possible mettings :>> " << maxMeetingsCnt << "\n";
            cout<<"The order in which the meetings will be performed is "<< endl;
            for (int i = 0; i < canBeArrangedMeetings.size(); i++) {
                cout << canBeArrangedMeetings[i] << " ";
            }

            cout << "\n";
            
        }

};
int main() {
   Solution obj;
   int n = 6;
   int start[] = {1,3,0,5,8,5};
   int end[] = {2,4,5,7,9,9};
   obj.maxMeetings(start, end, n);
   return 0;
}