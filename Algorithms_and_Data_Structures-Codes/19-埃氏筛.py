class Solution:
    global v
    def is_prime(self,n:int)->int:
        cnt=0
        v[0]=v[1]=1
        for i in range(2,n+1):
            if v[i]==0:
                cnt+=1
                for j in range(i+i,n+1,i):
                    v[j]=1
        return cnt
 
if __name__=='__main__':
    v=[0]*10001000  # 这个开空间比较容易出问题
    n=int(input())
    # print(type(n))
    res=Solution.is_prime(Solution,n)
    print(res)
 
 
'''
下面的代码能AC掉力扣上的题:
class Solution:
    def countPrimes(self, n: int) -> int:
        v=[0]*10000000
        cnt=0
        v[0]=v[1]=1
        for i in range(2,n):
            if v[i]==0:
                cnt+=1
                for j in range(i+i,n+1,i):
                    v[j]=1
        return cnt
'''