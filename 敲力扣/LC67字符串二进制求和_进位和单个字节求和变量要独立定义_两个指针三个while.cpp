#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//执行用时：4 ms, 在所有 C++ 提交中击败了47.39%的用户
//内存消耗：7.3 MB, 在所有 C++ 提交中击败了5.04%的用户

class Solution {
public:
    string addBinary(string a, string b) {
        int alen=a.size()-1;
        int blen=b.size()-1;
        string ans="";
        int carry=0;
        while(alen>=0&&blen>=0){
            int sum=carry;
            sum+=a[alen--]-'0';
            sum+=b[blen--]-'0';
            carry=sum/2;
            ans = ans + (char)(sum%2+'0');
        }

        while(alen>=0){
            if(carry==1){
                int sum=carry;
                sum+=a[alen--]-'0';
                carry=sum/2;
                ans+=(char)(sum%2+'0');
            }else
                ans+=a[alen--];
        }
        while(blen>=0){
            if(carry==1){
                int sum=carry;
                sum+=b[blen--]-'0';
                carry=sum/2;
                ans+=(char)(sum%2+'0');
            }else
                ans+=b[blen--];
        }
        if(carry)
            ans+=(char)(carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    string a,b;
    cin>>a>>b;
    Solution sol;
    string ans=sol.addBinary(a,b);
    cout<<ans<<endl;
    return 0;
}