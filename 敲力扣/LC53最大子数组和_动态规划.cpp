#include<iostream>
#include<vector>
using namespace std;

//执行用时：84 ms, 在所有 C++ 提交中击败了82.07%的用户
//内存消耗：66.1 MB, 在所有 C++ 提交中击败了67.01%的用户

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        int ans=nums[0], sum=0;
        for(int i=0;i<len;i++){
            if(sum<0){
                sum=nums[i];
            }else{
                sum+=nums[i];
            }

            if(ans<sum){
                ans=sum;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums;
    int num, len;
    cin>>len;
    for(int i=0;i<len;i++){
        cin>>num;
        nums.emplace_back(num);
    }
    Solution sol;
    int ans=sol.maxSubArray(nums);
    cout<<ans<<endl;
    return 0;
}