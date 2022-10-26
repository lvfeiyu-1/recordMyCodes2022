N,M=map(int,input().split())
ans=N
cat=[0 for _ in range(N+2)]
cap=[0 for _ in range(N+2)]

def dfs(now:int,cnt:int)->None:
    global ans,cat,cap
    if cnt>=ans:
        return
    if now==N+1:
        ans=min(ans,cnt)
        return
    for i in range(1,cnt+1):
        if cap[i]+cat[now]<=M:
            cap[i]+=cat[now]
            dfs(now+1,cnt)
            cap[i]-=cat[now]
    cap[cnt+1]=cat[now]
    dfs(now+1,cnt+1)
    cap[cnt+1]-=cat[now]

for i in range(1,N+1):
    cat[i]=int(input())

# for i in range(0,N+1):
#     print(cat[i])

cat.sort(reverse=True)
cat=[0]+cat
dfs(1,0)

print(ans)

# for i in range(1,N+1):
#     print(cat[i])