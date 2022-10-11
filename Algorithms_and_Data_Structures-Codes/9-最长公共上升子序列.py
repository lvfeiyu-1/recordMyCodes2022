N=int(input())

a=[0]+list(map(int,input().split()))
b=[0]+list(map(int,input().split()))

dp=[[0 for i in range(N+2)] for j in range(N+2)]

for i in range(1,N+1):
    for j in range(1,N+1):
        dp[i][j]=dp[i-1][j]
        if a[i]==b[j]:
            for k in range(1,j):
                if b[j]>b[k]:
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+1)

print(max(dp[N]))

'''
/*另一个三重循环*/
for (int i = 1; i <= n; i ++ )
{
    for (int j = 1; j <= n; j ++ )
    {
        f[i][j] = f[i - 1][j];
        if (a[i] == b[j])
        {
            int maxv = 1;
            for (int k = 1; k < j; k ++ )
                if (a[i] > b[k])
                    maxv = max(maxv, f[i - 1][k] + 1);
            f[i][j] = max(f[i][j], maxv);
        }
    }
}
'''

# 优化版
N=int(input())

a=[0]+list(map(int,input().split()))
b=[0]+list(map(int,input().split()))

dp=[[0 for i in range(N+2)] for j in range(N+2)]

for i in range(1,N+1):
    maxv=1
    for j in range(1,N+1):
        dp[i][j]=dp[i-1][j]
        if a[i]==b[j]:
            dp[i][j]=max(dp[i][j],maxv)
        if b[j]<a[i]:
            maxv=max(maxv,dp[i-1][j]+1)

print(max(dp[N]))

