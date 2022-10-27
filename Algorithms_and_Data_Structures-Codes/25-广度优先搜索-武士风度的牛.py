class pair:
    x,y=0,0
    def _init_(self)->None:
        self.x, self.y = 0, 0

def bfs(start:pair,end:pair)->int:
    global n,m,dist,g
    dx=[-2,-1,1,2,2,1,-1,-2]
    dy=[1,2,2,1,-1,-2,-2,-1]
    q=[]  # 用列表代替队列快多了
    dist[start.x][start.y]=0
    q.append(start)

    while len(q):
        t=q.pop(0)
##        print(t)
        for i in range(8):
            nx,ny=t.x+dx[i],t.y+dy[i]
            if nx<0 or nx>=n or ny<0 or ny>=m or g[nx][ny]=='*' or dist[nx][ny]!=-1:
                continue
            dist[nx][ny]=dist[t.x][t.y]+1
            if nx==end.x and ny==end.y:
                return dist[nx][ny]
            tmp=pair()
            tmp.x,tmp.y=nx,ny
            q.append(tmp)
    return -1

N=155
dist=[[-1]*N for _ in range(N)]
g=[]

m,n=map(int,input().split())

for i in range(n):
    g.append(input())

_start=pair()
_end=pair()

for i in range(n):
    for j in range(m):
        if g[i][j]=='K':
            _start.x=i
            _start.y=j
        elif g[i][j]=='H':
            _end.x=i
            _end.y=j

print(bfs(_start,_end))



'''
from queue import Queue

class pair:
    x,y=0,0
    def _init_(self)->None:
        self.x, self.y = 0, 0

def bfs(start:pair,end:pair)->int:
    global n,m,dist,g
    dx=[-2,-1,1,2,2,1,-1,-2]
    dy=[1,2,2,1,-1,-2,-2,-1]
    q=Queue() #显然这个是可以定义无限长度的
    dist[start.x][start.y]=0
    q.put(start)

    while q.qsize():
        t=q.get()
##        print(t)
        for i in range(8):
            nx,ny=t.x+dx[i],t.y+dy[i]
            if nx<0 or nx>=n or ny<0 or ny>=m or g[nx][ny]=='*' or dist[nx][ny]!=-1:
                continue
            dist[nx][ny]=dist[t.x][t.y]+1
            if nx==end.x and ny==end.y:
                return dist[nx][ny]
            tmp=pair()
            tmp.x,tmp.y=nx,ny
            q.put(tmp)
    return -1

N=155
dist=[[-1]*N for _ in range(N)]
g=[]

m,n=map(int,input().split())

for i in range(n):
    g.append(input())

_start=pair()
_end=pair()

for i in range(n):
    for j in range(m):
        if g[i][j]=='K':
            _start.x=i
            _start.y=j
        elif g[i][j]=='H':
            _end.x=i
            _end.y=j

print(bfs(_start,_end))
'''
