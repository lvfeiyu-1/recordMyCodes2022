N=int(input())

num=[0]+list(map(int,input().split()))
# 经调试发现dp是对num的浅拷贝(引用)，修改dp会同步修改到num
# dp=num 

# 应该这么copy
import copy
dp = copy.deepcopy(num)  # 看到没！deepcopy！深拷贝！

for i in range(2,N+1):
    for j in range(1,i):
        if num[i]>num[j]:
            dp[i]=max(dp[i],dp[j]+num[i])
    # print("{} {}".format(num[i],dp[i]))

print(max(dp))
