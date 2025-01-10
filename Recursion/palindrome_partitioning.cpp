#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        func(0, s, path, res);
        return res;
    }
    
    void func(int index, string s, vector<string> &path, vector<vector<string>> &res) {
        if(index == s.size()) {
            res.push_back(path);
            return;
        }
        
        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i-index+1));
                cout << "pushing :>> " << path.back() << "\n";
                func(i+1, s, path, res);
                cout << "popping :>> " << path.back() << "\n";
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

int main() {
    // string str = "ababbbabbababa";
    string str = "abba";
    Solution obj;
    vector<vector<string>> res = obj.partition(str);

    for (auto it : res) {
        for (auto palStr : it) {
            cout << palStr << " ";
        }
        cout << "\n";
    }
}