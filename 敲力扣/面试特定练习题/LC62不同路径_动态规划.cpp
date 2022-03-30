#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

//动态规划
//执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗：6.4 MB, 在所有 C++ 提交中击败了32.66%的用户
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1));

        //注释完后正确
        //dp[0][0]=0;
        //for(int i=0;i<m;i++)
            //dp[i][0]=1;
        //for(int i=0;i<n;i++)
            //dp[0][i]=1;
        for(int i=1;i<m;++i){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    int m,n;
    cin>>m>>n;
    Solution sol;
    int ans=sol.uniquePaths(m,n);
    cout<<ans<<endl;
    return 0;
}