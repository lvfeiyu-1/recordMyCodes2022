class Solution:
    def max_value(self,n,m,v,w):
        dp=[0]*(m+1)
        for i in range(1,n+1):
            for j in range(m,v[i]-1,-1):
                dp[j]=max(dp[j],dp[j-v[i]]+w[i])
        return dp[m]

if __name__=='__main__':
    import sys

    n,m=map(int,input().split())
    lines=sys.stdin.readlines()
    v=[0]
    w=[0]
    n=0
    for line in lines:
        line=list(map(int,line.split()))
        v.extend([line[0]]*line[2])
        w.extend([line[1]]*line[2])
        n+=line[2]
    print(Solution.max_value(n,m,v,w))

# 这一份代码主要帮助你复习和新了解下面的函数
# 1、强制转换 list()
# 2、列表的extend
# 3、多行输入 readlines()

# extend() 函数用于在列表末尾一次性追加另一个序列中的多个值（用新列表扩展原来的列表）。
