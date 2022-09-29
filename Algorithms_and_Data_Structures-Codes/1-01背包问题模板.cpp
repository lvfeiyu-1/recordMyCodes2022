#include <iostream>
using namespace std;

const int MAXN=1003;
int V[MAXN];    //每个背包的体积
int W[MAXN];    //每个背包的价值
int dp[MAXN][MAXN];    //dp[i][j], j体积下前i个物品的最大价值

int main() {
    int n,v;
    cin>>n>>v;

    for(int i=1;i<=n;++i)
        cin>>V[i]>>W[i];

    for(int i=1;i<=n;++i){       //该层循环为了遍历每个背包
        for(int j=1;j<=v;++j){      //为了填表中的每一行，得到在背包任意体积下的最优解，填表见下图
            if(j<V[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-V[i]]+W[i]);
        }
    }

    cout<<dp[n][v]<<endl;
    return 0;
}
/* 补充：
 * 当前的状态依赖于之前的状态，我们可以默认为从初始状态（边界） dp[0][j] = dp[i][0] = 0开始决策，
 * 有 N 件物品，则需要 N 次决 策，每一次对第 i 件物品的决策，状态dp[i][j]不断由之前的状态更新而来。
 * 显然，当只有 0 件物品的时候，或者背包最大容量为 0 的时候， dp[0][j] = dp[i][0] = 0
 * */
