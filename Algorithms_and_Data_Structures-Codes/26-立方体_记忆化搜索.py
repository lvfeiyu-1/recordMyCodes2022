import copy
 
n=0
N=1100
g=[]
f=[[-1]*N for _ in range(N)]
_f=[[-1]*N for _ in range(N)]
 
def dp(x:int,y:int)->int:
    v=f[x][y]
    if v!=-1:
        return v;
 
    v=1
    for i,j in {(-1,0),(0,1),(1,0),(0,-1)}:
        a,b=x+i,y+j
        if 0<=a<n and 0<=b<n and g[a][b]==g[x][y]+1:
            v=max(v,dp(a,b)+1)
 
    f[x][y]=v
    return v
 
T=int(input())
for case in range(1,T+1):
    g.clear()    # 这里有个坑，要对列表进行清空
    n=int(input())  # 一旦回车便执行完毕
    for i in range(n):
        line=list(map(int,input().split()))
        g.append(line)
 
    f=copy.deepcopy(_f)
 
    _id,maxn=0,0
 
    for i in range(n):
        for j in range(n):
            t=dp(i,j)
            if t>maxn or t==maxn and _id>g[i][j]:
                _id=g[i][j]
                maxn=t
 
    print("Case #{}: {} {}".format(case,_id,maxn))
    
    
# python代码是过不了的，原因在于输入的问题。