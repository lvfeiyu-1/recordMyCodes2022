MAXN=1010
V=[0]*MAXN
W=[0]*MAXN
dp=[0]*MAXN
 
n,v=map(int,input().split())
 
for i in range(1,n+1):
    V[i],W[i]=map(int,input().split())
 
for i in range(1,n+1):
    for j in range(V[i],v+1):
        dp[j]=max(dp[j],dp[j-V[i]]+W[i])
 
print(dp[v])