#include<iostream>
#include<vector>
using namespace std;

//滑动窗口
//执行用时：4 ms, 在所有 C++ 提交中击败了94.01%的用户
//内存消耗：10.3 MB, 在所有 C++ 提交中击败了30.58%的用户
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len=nums.size();
        int start=0,end=0,sum=0,ans=999999999;

        while(end<len){
            sum+=nums[end];
            while(sum>=target){
                ans=ans>(end-start+1)?(end-start+1):ans;
                sum-=nums[start];
                start++;
            }
            end++;
            if(ans==1)
                break;
        }

        return ans==999999999?0:ans;
    }
};

int main(){
    vector<int> nums;
    int target,n,num;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        nums.emplace_back(num);
    }
    cin>>target;
    Solution sol;
    int ans=sol.minSubArrayLen(target,nums);
    cout<<ans<<endl;
    return 0;
}