#include<iostream>
#include<string>
using namespace std;

//执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗：6.4 MB, 在所有 C++ 提交中击败了33.79%的用户

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        int flg=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' '&&flg==1)
                break;
            if(s[i]!=' '){
                len++;
                flg=1;
            }
            else{
                continue;
            }
        }
        return len;
    }
};

int main(){
    string s;
    getline(cin,s);
    //cout<<s<<endl;
    Solution sol;
    int ans=sol.lengthOfLastWord(s);
    cout<<ans<<endl;
    return 0;
}