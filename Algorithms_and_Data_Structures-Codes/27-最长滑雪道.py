n,m=map(int,input().split())
Map=[]
ans=0
for i in range(n):
    Map.append(list(map(int,input().split())))

dp=[[-1 for i in range(m)] for j in range(n)] # 先列再行

def dfs(x,y):
    global dp
    if dp[x][y]!=-1:
        return dp[x][y]
    
    t=1
    for i,j in [(1,0),(0,1),(-1,0),(0,-1)]:
        px=x+i
        py=y+j
        if 0<=px<n and 0<=py<m and Map[px][py]<Map[x][y]:
            t=max(t,dfs(px,py)+1)
    
    dp[x][y]=t
    return t

for i in range(n):
    for j in range(m):
        dfs(i,j)
    
for i in range(n):
    for j in range(m):
        ans=max(ans,dp[i][j])

print(ans)