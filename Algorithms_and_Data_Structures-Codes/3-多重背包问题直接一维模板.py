MAXN = 110
w=[0]*MAXN
v=[0]*MAXN
num=[0]*MAXN
dp=[0]*MAXN

N,V=map(int,input().split())

for i in range(1,N+1):
    v[i],w[i],num[i]=map(int,input().split())

for i in range(1,N+1):
    for j in range(V,v[i]-1,-1):
        for k in range(num[i]+1):
            if k*v[i]>j:
                break
            dp[j]=max(dp[j],dp[j-k*v[i]]+k*w[i])
print(dp[V])


# 下面根据一维写二维
'''
MAXN = 110
w=[0 for i in range(MAXN)]
# w=[0]*MAXN
v=[0 for i in range(MAXN)]
# v=[0]*MAXN
num=[0 for i in range(MAXN)]
# num=[0]*MAXN
dp=[[0 for i in range(MAXN)] for j in range(MAXN)]

N,V = map(int,input().split())

for i in range(1,N+1):
    v[i],w[i],num[i]=map(int,input().split())

for i in range(1,N+1):
    for j in range(0,V+1):   # 注意一下这个循环的循环条件
        for k in range(num[i]+1): 
            if k*v[i]>j:
                break
            #这里需要注意一下，不能像下面注释的那样写，如果这样写的话
            #就永远是（不选）与（选k个）做比较了
            #就没有（选k-1个）与（选k个）做比较了
            #dp[i][j]=max(dp[i-1][j],dp[i-1][j-k*v[i]]+k*w[i])  
            dp[i][j]=max(dp[i][j],dp[i-1][j-k*v[i]]+k*w[i])
print(dp[N][V])
'''

