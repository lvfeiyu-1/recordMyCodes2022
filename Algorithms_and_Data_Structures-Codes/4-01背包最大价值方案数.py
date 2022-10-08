# 一维空间存储数据
mod=1e9+7
MAXN=1010
v=[0]*MAXN
w=[0]*MAXN
dp=[0]*MAXN
cnt=[1]*MAXN
 
N,V=map(int,input().split())
 
for i in range(1,N+1):
    v[i],w[i]=map(int,input().split())
 
for i in range(1,N+1):
    for j in range(V,v[i]-1,-1):
        if dp[j-v[i]]+w[i] > dp[j]:
            dp[j]=dp[j-v[i]]+w[i]
            cnt[j]=cnt[j-v[i]]
        elif dp[j-v[i]]+w[i] == dp[j]:
            cnt[j]=(cnt[j]+cnt[j-v[i]])%mod
 
print(int(cnt[V]))


# 优化存储空间
# mod=1e9+7
# MAXN=1010
# # v=[0]*MAXN
# # w=[0]*MAXN
# dp=[0]*MAXN
# cnt=[1]*MAXN
 
# N,V=map(int,input().split())
 
# # for i in range(1,N+1):
# #     v[i],w[i]=map(int,input().split())
 
# for i in range(1,N+1):
#     v,w=map(int,input().split())
#     for j in range(V,v-1,-1):
#         if dp[j-v]+w > dp[j]:
#             dp[j]=dp[j-v]+w
#             cnt[j]=cnt[j-v]
#         elif dp[j-v]+w == dp[j]:
#             cnt[j]=(cnt[j]+cnt[j-v])%mod
 
# print(int(cnt[V]))


# -------------------
'''
怎么求解恰好装满01背包, 并且是最优选法的方案数呢？
先上两个代码看差别：

(1) 不超过容量的初始化
MAXN=1010
cnt=[1]*MAXN  #cnt全部初始化为1

(2) 恰好装满背包的初始化
MAXN=1010
dp=[-1000]*MAXN
dp[0]=0         #
cnt=[0]*MAXN
cnt[0]=1        #

'''
