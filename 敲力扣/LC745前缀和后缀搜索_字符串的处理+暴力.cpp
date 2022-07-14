#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

//答案的暴力求解法。而使用暴力法，那么这个题目将完全没有意义，你明天
//应该用字典树再敲一遍

/*
 * 执行用时：1008 ms, 在所有 C++ 提交中击败了16.41%的用户
 * 内存消耗：254.1 MB, 在所有 C++ 提交中击败了33.85%的用户
 * */
class WordFilter {
private:
    unordered_map<string,int> dict;
public:
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();++i){
            int m=words[i].size();
            string word=words[i];
            for(int prefixLen=1;prefixLen<=m;prefixLen++){
                for(int suffixLen=1;suffixLen<=m;++suffixLen){
                    string key=word.substr(0,prefixLen)+"#"+word.substr(m-suffixLen);
                    dict[key]=i;
                }
            }
        }
    }

    int f(string pref, string suff) {
        string target=pref+"#"+suff;
        return dict.count(target)?dict[target]:-1;
    }
};

int main(){

}

/*
 * 设计一个包含一些单词的特殊词典，并能够通过前缀和后缀来检索单词。
 * 实现 WordFilter 类：
    WordFilter(string[] words) 使用词典中的单词 words 初始化对象。
    f(string pref, string suff) 返回词典中具有前缀prefix和后缀 suff的单词的下标。
    如果存在不止一个满足要求的下标，返回其中 最大的下标 。如果不存在这样的单词，返回 -1 。
 */

/*
输入
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
输出
[null, 0]
解释
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // 返回 0 ，因为下标为 0 的单词：前缀 prefix = "a" 且 后缀 suff = "e" 。
*/

