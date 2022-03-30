#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

//参考答案，三维dp解决
//执行用时：624 ms, 在所有 C++ 提交中击败了7.42%的用户
//内存消耗：266.4 MB, 在所有 C++ 提交中击败了5.06%的用户
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int n=prices.size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(2,0)));

        for(int i=0;i<n;i++){
            for(int j=1;j<=2;j++){
                if(i==0){
                    dp[i][j][1]=-prices[i];
                    continue;
                }
                dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]+prices[i]);
                dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][0]-prices[i]);
            }
        }
        return dp[n-1][2][0];
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
    int ans=sol.maxProfit(nums);
    cout<<ans<<endl;
    return 0;
}