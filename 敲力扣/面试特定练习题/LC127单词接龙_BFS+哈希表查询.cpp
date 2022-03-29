#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>
using namespace std;

//BFS+哈希表查询
//执行用时：92 ms, 在所有 C++ 提交中击败了69.20%的用户
//内存消耗：14.9 MB, 在所有 C++ 提交中击败了59.10%的用户
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());
        if(words.size()==0||words.find(endWord)==words.end())
            return 0;
        unordered_set<string> visited;
        visited.emplace(beginWord);

        queue<string> que;
        que.emplace(beginWord);
        if(words.find(beginWord)!=words.end())
            words.erase(beginWord);

        int step=1;
        while(!que.empty()){
            int n=que.size();

            while(n--){
                string word=que.front();
                que.pop();

                for(int i=0;i<word.size();i++){
                    char currentChar=word[i];
                    for(int j=0;j<26;j++){
                        if((char)('a'+j)==currentChar)
                            continue;
                        word[i]=(char)('a'+j);
                        if(words.find(word)!=words.end()&&visited.find(word)==visited.end()){
                            if(word==endWord)
                                return step+1;
                            else{
                                que.emplace(word);
                                visited.emplace(word);
                            }
                        }
                    }
                    word[i]=currentChar;
                }
            }
            step++;
        }
        return 0;
    }
};

//C++答案
class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        //迭代器构造哈希表
        unordered_set<string> words(wordList.begin(), wordList.end());
        //哈希表为空 或者 哈希表不存在目标字符串
        if (words.empty() || words.find(endWord) == words.end())
            return 0;

        words.erase(beginWord);
        queue<string> que;
        que.push(beginWord);
        // FIXME: 不需要visited，每个单词如果被访问到了就直接从words中删除就可以了
        unordered_set<string> visited;
        visited.insert(beginWord);
        int step = 1;
        while (!que.empty()) {
            // 找到没有被访问过, 而且能够由当前单词转换而成的单词
            int n = que.size();
            // 每一轮(每一层step加个1)
            while (n--) {
                string curWord = que.front();
                que.pop();
                // 当前单词的每个字符都替换成其他的25个字符, 然后在单词表中查询
                // 是不是包含转换后的单词
                // 这里千万不能遍历单词表, 因为单词表很长, 而哈希表使用的红黑树
                // 的查询效率比遍历单词表高很多
                for (int i = 0; i < curWord.size(); ++i) {
                    char originalChar = curWord[i];
                    for (int j = 0; j < 26; ++j) {
                        if (char('a' + j) == originalChar)
                            continue;
                        curWord[i] = (char) ('a' + j);
                        if (words.find(curWord) != words.end() &&
                        visited.find(curWord) == visited.end()) {
                            if (curWord == endWord)
                                return step + 1;
                            else {
                                que.push(curWord);
                                visited.insert(curWord);
                            }
                        }
                    }
                    curWord[i] = originalChar;
                }
            }
            ++step;
        }
        return 0;
    }
};

int main() {
    vector<string> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string num;
        cin >> num;
        nums.emplace_back(num);
    }
    string begin, end;
    cin >> begin >> end;
    Solution sol;
    int ans = sol.ladderLength(begin, end, nums);
    cout << ans << endl;
    return 0;
}