N,M=map(int,input().split())

fa=[i for i in range(N+1)]  # 包含了初始化

def Find(x):        # 找自己的父亲，进行了路径压缩
    if fa[x]==x:
        return x
    fa[x]=Find(fa[x])
    return fa[x]

def union(x,y):   # 将两个不在同一集合的节点合并
    tx=Find(x)
    ty=Find(y)
    fa[tx]=ty

for i in range(M):
    z,x,y=map(int,input().split())
    if z==1:
        if Find(x)!=Find(y):
            union(x,y)
    elif z==2:
        if Find(x)==Find(y):
            print("Y")
        else:
            print("N")