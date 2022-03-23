#include<iostream>
#include<string>
using namespace std;

//滑动区间
//执行用时：8 ms, 在所有 C++ 提交中击败了47.04%的用户
//内存消耗：8 MB, 在所有 C++ 提交中击败了41.40%的用户

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int slen=s.size();
        int tlen=t.size();
        int len=min(slen,tlen);

        int* cnt=new int[len];
        for(int i=0;i<len;i++){
            cnt[i]=abs(s[i]-t[i]);
        }

        int left=0,right=0,sum=0,ans=0;
        while(right<len){
            sum+=cnt[right];
            while(sum>maxCost){
                sum-=cnt[left++];
            }
            ans=max(ans,right-left+1);
            right++;
        }

        //下面注释的这段代码 过32/37，暂时没找出原因
//        while(left<len){
//            while(sum<=maxCost&&right<len){
//                sum+=cnt[right];
//                right++;
//            }
//            ans=max(ans,right-left-1);
//            sum-=cnt[left];
//            left++;
//        }
        return ans;
    }
};

int main(){
    string s,t;
    cin>>s>>t;
    int maxCost;
    cin>>maxCost;
    Solution sol;
    int ans=sol.equalSubstring(s,t,maxCost);
    cout<<ans<<endl;
    return 0;
}