#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    int lengthofLongestSubstring(string s) {
      int maxSubstrLen = 0;

      int l = 0, r = 0;
      int nSize = s.size();

      vector < int > mpp(256, -1);

      while (r < nSize) {
        if (mpp[s[r]] != -1) {
            if (mpp[s[r]] >= l) {
                l = mpp[s[r]]+1;
            }
        }
        maxSubstrLen = max(maxSubstrLen, r-l+1);
        mpp[s[r]] = r;
        r++;
      }

      return maxSubstrLen;
    }
};

int main() {
  string str = "takeUforward";
  Solution obj;
  cout << "The length of the longest substring without repeating characters is " << obj.lengthofLongestSubstring(str) << "\n";
  return 0;
}