
h=list(map(int,input().split()))  # 输入一组序列
n=len(h)
# print(n)

dp=[1]*(n+1)

for i in range(1,n):
    for j in range(0,i):
        if h[j]>h[i]:
            dp[i]=max(dp[i],dp[j]+1)

print(max(dp))  # 用函数max直接找到dp数组的最大值，无需再遍历了

# 分割线------------------------下面是求拦截导弹用了多少套系统
cnt=[1]*(n+1)
for i in range(1,n):
    for j in range(0,i):
        if h[j]<h[i]:
            cnt[i]+=1
            break

# for i in range(n):
#     print(cnt[i],end=" ")
# print("")

print(max(cnt))
