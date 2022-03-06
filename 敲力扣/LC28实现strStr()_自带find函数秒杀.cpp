#include<iostream>
#include<string>
using namespace std;

//执行用时：16 ms, 在所有 C++ 提交中击败了46.97%的用户
//内存消耗：7 MB, 在所有 C++ 提交中击败了64.23%的用户

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

int main(){
    string haystack,needle;
    cin>>haystack>>needle;
    Solution sol;
    //int ans=sol.strStr(haystack,needle);
    int ans=sol.strStr("","");
    cout<<ans<<endl;
    return 0;
}