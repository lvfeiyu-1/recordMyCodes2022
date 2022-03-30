#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

//本质动态规划，加之根据题目要求变通处理一下
//执行用时：4 ms, 在所有 C++ 提交中击败了55.67%的用户
//内存消耗：7.7 MB, 在所有 C++ 提交中击败了11.07%的用户
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]==1)
                break;
            dp[i][0]=1;
        }

        for(int i=0;i<n;i++){
            if(obstacleGrid[0][i]==1){
                break;
            }
            dp[0][i]=1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1)
                    dp[i][j]=0;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};

int main() {
    int m,n;
    cin>>m>>n;
    vector<vector<int>> ob;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            ob.emplace_back(num);
        }
    }
    Solution sol;
    int ans=sol.uniquePathsWithObstacles(ob);
    cout<<ans<<endl;
    return 0;
}