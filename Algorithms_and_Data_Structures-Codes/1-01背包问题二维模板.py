MAXN=1003
dp=[[0]*MAXN for i in range(MAXN+1)] #注意创建二维数组是这样子
V=[0]*MAXN
W=[0]*MAXN

# test=[[0]*MAXN]*MAXN   #这样创数组有错误
# print(test[10][10])

n,v=map(int,input().split())

for i in range(1,n+1):
    V[i],W[i]=map(int,input().split())

for i in range(1,n+1):
    for j in range(1,v+1):
        if j<V[i]:
            dp[i][j]=dp[i-1][j]
        else:
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-V[i]]+W[i])

print(dp[n][v])

# 以下单注释的是曹老板写的，运行的话记得全部注释掉
# n,v = map(int,input().split())
# #dp = np.zeros([n+1,v+1],dtype=int)
# #V = np.zeros(n+1,dtype=int)
# #W = np.zeros(n+1,dtype=int)
# dp = []
# for i in range(n+1):
#     tmp = []
#     for j in range(v+1):
#         tmp.append(0)
#     dp.append(tmp)

# V = []
# for i in range(n+1):
#     V.append(0)
# W =[]
# for i in range(n+1):
#     W.append(0)

# for i in range(1,n + 1):
#     V[i],W[i] = map(int,input().split())

# for i in range(1,n + 1):
#     for j in range(1,v + 1):
#         if j < V[i]:
#             dp[i][j] = dp[i - 1][j]
#         else:
#             dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - V[i]] + W[i])

# #for i in range(1,n + 1):
# #    for j in range(1,v + 1):
# #        print(str(dp[i][j]),end=" ")
# #    print("")

# print("%d" % dp[n][v])
# #print(dp[n][v])

