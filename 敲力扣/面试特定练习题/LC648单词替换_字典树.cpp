#include<vector>
#include<iostream>
#include<algorithm>
#include<sstream>

using namespace std;

//字典树
//执行用时：36 ms, 在所有 C++ 提交中击败了85.54%的用户
//内存消耗：53.6 MB, 在所有 C++ 提交中击败了46.98%的用户
class TrieNode {
public:
    TrieNode *children[26];
    char val;
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; ++i)
            children[i] = NULL;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *cur = root;

        for (int i = 0; i < word.size(); ++i) {
            int c = word[i] - 'a';
            if (cur->children[c] == NULL) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isEnd = true;
    }

    string findPrefix(string &word){       //找前缀
        auto node = root;
        string res = "";
        for (auto ch : word) {
            if (node->isEnd || node->children[ch-'a']==nullptr)
                break;
            res += ch;
            node = node->children[ch-'a'];
        }
        return node->isEnd?res:"";         //有前缀返回前缀，没有则返回空字符串
    }

};

class Solution {
public:
    string replaceWords(vector<string> &dictionary, string sentence) {
        Trie *trie = new Trie();
        for (string &str:dictionary) {
            trie->insert(str);
        }

        //C++这里的挑选字符串真的是惊艳到我了，具体用法可以看看笔记
        vector<string> collect;
        istringstream temp(sentence);
        string s;
        while (temp >> s)
            collect.emplace_back(s);

        string ans="";
        int i=0;
        for(i=0;i<collect.size()-1;++i){
            string ch=collect[i];
            string prefix=trie->findPrefix(ch);
            if(prefix=="")
                ans+=ch+" ";
            else
                ans+=prefix+" ";
        }

        string prefix=trie->findPrefix(collect[i]);
        if(prefix=="")
            ans+=collect[i];
        else
            ans+=prefix;
        return ans;
    }
};


int main() {
    vector<string> words;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        words.emplace_back(str);
    }
    string sentence;
    cin >> sentence;
    Solution sol;
    string ans = sol.replaceWords(words, sentence);
    cout << ans << endl;
    return 0;
}