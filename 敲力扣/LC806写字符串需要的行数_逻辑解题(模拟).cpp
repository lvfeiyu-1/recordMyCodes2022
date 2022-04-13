#include<iostream>
#include<vector>
#include<string>
using namespace std;

//逻辑解题
//执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗：6.7 MB, 在所有 C++ 提交中击败了44.52%的用户
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int n=s.size();
        if(n==0)
            return {0,0};
        int height=1;
        int cnt=0;
        for(int i=0;i<n;++i){
            int c=s[i];
            int tmplen=widths[c-'a'];
            if(cnt+tmplen<=100)
                cnt+=tmplen;
            else{
                cnt=tmplen;
                height++;
            }
        }
        return {height,cnt};
    }
};

int main(){
    vector<int> widths;
    string s;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int num;
        cin>>num;
        widths.emplace_back(num);
    }
    cin>>s;
    Solution sol;
    vector<int> res=sol.numberOfLines(widths,s);
    for(auto& a:res)
        cout<<a<<" ";
    cout<<endl;
    return 0;
}