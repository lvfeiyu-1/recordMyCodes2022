n,m=map(int,input().split())
a=[0]*500009 # a是待输入的数组 
t=[0]*500009 # t是树状数组,t[x]保存以x为根的子树中叶节点值的和

def createTree():  # 构建树状维护数组 t 
    global t
    for i in range(1,n+1):
        j=i+(i&-i)   # 当前节点的父亲 
        if j<n+1:
            t[j]+=t[i]

def lowbits(x)->int:  # 没用的函数，只是说x的lowbits就是x&-x
    return x&-x

def add(x,k):
    while(x<=n):
        t[x]+=k
        x+=x&-x

def ask(x)->int:
    ans=0
    while(x>0):
        ans+=t[x]
        x-=x&-x
    return ans

line=[0]+list(map(int,input().split()))
for i in range(1,n+1):
    a[i]=line[i]
    t[i]=line[i]

createTree()

for _ in range(m):
    x,y,z=map(int,input().split())
    if x==1:
        add(y,z)
    elif x==2:
        ans=ask(z)-ask(y-1)
        print(ans)
    else:
        print("error")
