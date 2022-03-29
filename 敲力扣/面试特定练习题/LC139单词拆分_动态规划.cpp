#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>
using namespace std;

//动态规划
//执行用时：12 ms, 在所有 C++ 提交中击败了62.11%的用户
//内存消耗：12.8 MB, 在所有 C++ 提交中击败了54.56%的用户
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        int len=s.size();
        vector<bool> dp(len, false);
        dp[0]=true;

        for(int i=0;i<=len;i++){
            for(int j=0;j<i;j++){
                if(dp[j]&&words.find(s.substr(j,i-j))!=words.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[len];
    }
};

int main() {
    string s;
    vector<string> wordDict;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string tmp;
        wordDict.emplace_back(tmp);
    }
    Solution sol;
    bool ans = sol.wordBreak(s, wordDict);
    cout << ans << endl;
    return 0;
}