#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

//执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗：8.1 MB, 在所有 C++ 提交中击败了94.95%的用户
class Solution {
public:
    int uniqueMorseRepresentations(vector<string> &words) {
        string trans[] ={".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
                         ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
                         "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_map<string, int> mp;
        int res=0;
        for(auto& word:words){
            string tmp="";
            for(int i=0;i<word.size();++i){
                tmp+=trans[word[i]-'a'];
            }
            //这题只是这个find和insert要注意一下
            if(mp.find(tmp)==mp.end()){
                res++;
                mp.insert(pair<string,int>(tmp,1));
            }
        }
        return res;
    }
};

int main() {
    vector<string> words;
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        words.emplace_back(s);
    }
    Solution sol;
    int ans = sol.uniqueMorseRepresentations(words);
    cout << ans << endl;
    return 0;
}