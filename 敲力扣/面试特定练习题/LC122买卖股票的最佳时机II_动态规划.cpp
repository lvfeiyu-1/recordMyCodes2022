#include<iostream>
#include<vector>
using namespace std;

//动态规划，这一天的状态由前一天的状态分情况转移而来
//执行用时：4 ms, 在所有 C++ 提交中击败了89.53%的用户
//内存消耗：12.7 MB, 在所有 C++ 提交中击败了44.25%的用户
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        //dp[i][0]代表不持有股票，dp[i][1]代表持有股票
        int dp[n][2];
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
        }
        return dp[n-1][0];
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> prices;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        prices.emplace_back(num);
    }
    Solution sol;
    int ans=sol.maxProfit(prices);
    cout<<ans<<endl;
    return 0;
}