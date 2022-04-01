#include<vector>
#include<iostream>
using namespace std;

//字典树 或 前缀树
//执行用时：44 ms, 在所有 C++ 提交中击败了92.26%的用户
//内存消耗：44.1 MB, 在所有 C++ 提交中击败了58.00%的用户
class Trie {
    Trie* children[26];
    bool isEnd;
public:
    Trie() {
        isEnd= false;
        for(int i=0;i<26;++i)
            children[i]=NULL;
        //下面这样写在力扣会时间超限
//        Trie** children;
//        *children=new Trie[26];
    }

    void insert(string word) {
        Trie* node=this;
        for(int i=0;i<word.size();++i){
            char ch=word[i]-'a';
            if(node->children[ch] == NULL){
                node->children[ch]=new Trie();
            }
            node=node->children[ch];
        }
        node->isEnd= true;
    }

    bool search(string word) {
        Trie* node= searchPrefix(word);
        return node!=NULL&&node->isEnd==true;
    }

    bool startsWith(string prefix) {
        return searchPrefix(prefix)!=NULL;
    }

    Trie* searchPrefix(string prefix){
        Trie* node=this;
        for(int i=0;i<prefix.size();++i){
            char ch=prefix[i]-'a';
            if(node->children[ch]==NULL){
                return NULL;
            }
            node=node->children[ch];
        }
        return node;
    }
};


int main(){

    return 0;
}