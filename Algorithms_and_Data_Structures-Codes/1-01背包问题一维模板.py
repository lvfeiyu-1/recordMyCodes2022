MAXN=1003
dp=[0]*MAXN
V=[0]*MAXN
W=[0]*MAXN

n,v=map(int,input().split())

for i in range(1,n+1):
    V[i],W[i]=map(int,input().split())

for i in range(1,n+1):
    for j in range(v+1,0,-1):
        if j<V[i]:
            dp[j]=dp[j]
        else:
            dp[j]=max(dp[j],dp[j-V[i]]+W[i])

print(dp[v])

# dp=[0,1,2,3,4,5,6,7,8,9,10,11,21]
# for i in range(12,1,-1):   #这样是逆序输出
#     print(dp[i],end=" ")
