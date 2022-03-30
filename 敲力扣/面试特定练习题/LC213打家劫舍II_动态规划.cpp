#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

//LC198：打家劫舍      动态规划
//执行用时：4 ms, 在所有 C++ 提交中击败了25.62%的用户
//内存消耗：7.5 MB, 在所有 C++ 提交中击败了51.89%的用户
class Solution2 {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n=nums.size();
        if(n==1)
            return nums[0];

        int *dp=new int[n];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int i=2;i<n;i++)
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);

        return dp[n-1];
    }
};

//LC213：打家劫舍II      仿照198的动态规划
//执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗：7.7 MB, 在所有 C++ 提交中击败了46.20%的用户
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n=nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        int*dp1=new int[n];
        int* dp2=new int[n];
        dp1[0]=nums[0];
        dp1[1]=max(nums[0],nums[1]);

        dp2[1]=nums[1];
        dp2[2]=max(nums[1],nums[2]);

        for(int i=2;i<n-1;i++)
            dp1[i]=max(dp1[i-2]+nums[i],dp1[i-1]);

        for(int i=3;i<n;i++)
            dp2[i]=max(dp2[i-2]+nums[i],dp2[i-1]);

        return max(dp1[n-2],dp2[n-1]);
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.emplace_back(num);
    }

    Solution sol;
    int ans=sol.rob(nums);
    cout<<ans<<endl;
    return 0;
}