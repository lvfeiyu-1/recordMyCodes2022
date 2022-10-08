
n=int(input())

lists=[[0 for i in range(n+2)] for j in range(4)]

for i in range(2):
    lists[i]=list(map(int,input().split()))

dp=[[0 for i in range(n+2)] for j in range(n+2)]

maxValue=-1
# ans=[]
for i in range(1,n+1):
    for j in range(1,n+1):
        if lists[0][i-1]==lists[1][j-1]:
            dp[i][j]=dp[i-1][j-1]+1
        else:
            dp[i][j]=max(dp[i][j-1],dp[i-1][j])
        if dp[i][j]>maxValue:
            maxValue=dp[i][j]
            # if dp[i][j]>dp[i-1][j] and dp[i][j]>dp[i][j-1]:  #这个回溯找最长公共子串不一定对，但也能说明一定的问题，具体可以看看填的那张表的规律
                # ans.append(lists[0][i-1])

# print(ans)
print(maxValue) 
