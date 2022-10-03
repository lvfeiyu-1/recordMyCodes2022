MAXN=1010
V=[0]*MAXN
W=[0]*MAXN
dp=[[0]*MAXN for i in range(MAXN)]
 
n,v=map(int,input().split())
 
for i in range(1,n+1):
    V[i],W[i]=map(int,input().split())
 
for i in range(1,n+1):
    for j in range(0,v+1):
        if j<V[i]:
            dp[i][j]=dp[i-1][j]
        else:
            dp[i][j]=max(dp[i-1][j],dp[i][j-V[i]]+W[i])
 
print(dp[n][v])