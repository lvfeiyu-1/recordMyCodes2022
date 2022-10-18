
from itertools import combinations
res=[]
n,k=map(int,input().split())
for c in combinations(range(1,n+1),k):
    res.append(list(c))
print(res)


# leetcode 77题 方法一：python3内置函数
# 用时 44ms 击败 91.69%，内存 16.5MB 击败66.46%
'''
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        from itertools import combinations
        res=[]
        for c in combinations(range(1,n+1),k):
            res.append(list(c))
        return res
'''


# 方法二：python3递归
#时间 40 ms，击败 96.61%；内存 17.2 MB，击败 5.18%
'''
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        if k == 1: 
            return [[i] for i in range(1, n + 1)]
        if k == n: 
            return [list(range(1, n + 1))]
        return self.combine(n-1, k) + [x + [n] for x in self.combine(n - 1, k - 1)]
'''


# 方法三：建表存储信息（求组合数哦，不是求出所有组合哦！）
# 根据 c[i][j] = c[i-1][j]+c[i-1][j-1]，我们可以从上到下，从左到右依次填表即可
# global 标志实际上是为了提示 python 解释器，表明被其修饰的变量是全局变量。
# 这样解释器就可以从当前空间 (current scope) 中读写相应变量了。
'''
# 求组合数Cab 记住公式和边界条件,当j==0时,c[i][j]=1即可。
 
N=2010
mod=1e9+7 # 取模防止爆int
c=[[0 for i in range(N)] for j in range(N)]
 
def get():
  global c
  for i in range(N):
    for j in range(i+1):
      if(j==0): # 
        c[i][j]=1
      else: # 用公式计算c[i][j]
        c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod
 
n=int(input())
get()
for k in range(n):
  a,b=map(int,input().split())
  print(c[a][b])
'''

# 测试 combinations
'''
from itertools import combinations
y = {'a','a','a','b'}
for i in combinations(y,2):
    print (''.join('%s' % p for p in i))
'''
