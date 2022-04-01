#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//字典树
//执行用时：44 ms, 在所有 C++ 提交中击败了64.78%的用户
//内存消耗：72.1 MB, 在所有 C++ 提交中击败了47.94%的用户
class TrieNode {
public:
    TrieNode* children[26];
    char val;
    bool isEnd;

    TrieNode() {
        isEnd= false;
        for(int i=0;i<26;++i)
            children[i]=NULL;
    }
};

class Trie{
    TrieNode* root;
public:
    Trie(){
        root=new TrieNode();
    }
    int insert(string word){
        TrieNode* cur=root;
        bool isNew=false;

        //倒着插入
        for(int i=word.size()-1;i>=0;--i){
            int c=word[i]-'a';
            if(cur->children[c]==NULL){
                isNew=true;
                cur->children[c]=new TrieNode();
            }
            cur=cur->children[c];
        }
        return isNew?word.size()+1:0;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        //从长到短排序真实妙阿
        sort(words.begin(),words.end(),[](const string s1,const string s2){
            return s1.size()>s2.size();
        });
        int len=0;
        Trie* trie=new Trie();
        for(string& str:words){
            len+=trie->insert(str);
        }
        return len;
    }
};


int main(){
    vector<string> words;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        string str;
        cin>>str;
        words.emplace_back(str);
    }
    Solution sol;
    int ans=sol.minimumLengthEncoding(words);
    cout<<ans<<endl;
    return 0;
}