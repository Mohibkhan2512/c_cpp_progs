
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
 
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList) {
        queue<pair<string, int>> q;
        q.push({startWord, 1});

        unordered_set<string> ws(wordList.begin(), wordList.end());
        ws.erase(startWord);
        
        string aToz = "abcdefghijklmnopqrstuvwxyz";

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == targetWord) {
                return steps;
            }

            for (int i = 0; i < word.size(); i++) {
                char initalChar = word[i];
                for (char cA : aToz) { 
                    word[i] = cA;

                    if (ws.find(word) != ws.end()) {
                        ws.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = initalChar;
            }
        }

        // If transition not possible
        return 0;
    }
};

int main() {
 
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
 
    Solution obj;
 
    int ans = obj.wordLadderLength(startWord, targetWord, wordList);
 
    cout << "Num of transitions states required for converting startWord to targetWord :>> " << ans;
    cout << endl;
    return 0;
}