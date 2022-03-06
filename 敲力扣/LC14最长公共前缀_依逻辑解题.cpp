#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int strsLen=strs.size();
        int minLen=findLong(strs);
        for(int i=0;i<minLen;i++){
            int j=0;
            for(;j<strsLen-1;j++){
                if(strs[j][i]==strs[j+1][i])
                    continue;
                else
                    break;
            }
            if(j==strsLen-1)
                ans+=strs[j][i];
            else
                break;
        }
        return ans;
    }

    int findLong(vector<string>& strs){
        int len=strs.size();
        int minLen=999;
        for(int i=0;i<len;i++){
            if(minLen>strs[i].length()){
                minLen=strs[i].length();
            }
        }
        return minLen;
    }
};

int main(){
    vector<string> strs;
    string ch;
    while(cin>>ch){
        if(ch=="Z")
            break;
        strs.emplace_back(ch);
    }
    Solution sol;
    string ans=sol.longestCommonPrefix(strs);
    //cout<<"1"<<endl;
    cout<<ans<<endl;
    return 0;
}