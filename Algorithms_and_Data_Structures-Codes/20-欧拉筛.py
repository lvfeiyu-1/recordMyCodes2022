# 下面代码AC不了洛谷的例题，主要是因为空间的问题，算法思想和代码实现是没问题的
class Solution:
    global v,prime
    def is_prime(self,n:int)->None:
        cnt=0
        v[0]=v[1]=1
        for i in range(2,n+1):
            if v[i]==0:
                v[i]=i
                cnt+=1
                prime[cnt]=i
            for j in range(1,cnt+1):
                if prime[j]>n//i or prime[j]>v[i]:
                    break
                v[i*prime[j]]=prime[j]
 
if __name__=='__main__':
    v=[0]*55001000
    prime=[0]*800100
    n,q=map(int,input().split())
    # print(type(n))
    Solution.is_prime(Solution,n)
    for _ in range(q):
        k=int(input())
        print(prime[k])


# 另一个欧拉筛的模板
# 线性筛质数
N=1000010
n=int(input())
cnt=0 # 用来计算有几个素数
primes=[] # 用来存素数
def get_primes(n):
    global cnt,primes
    st=[False for i in range(N)] # 是否被筛过
    for i in range(2,n+1):
        if(st[i]==0): # 如果没被筛过 是素数
            primes.append(i) # 放到素数列表中
            cnt+=1
        for j in range(N):
            if(primes[j]>n//i): break # 枚举已经筛过的素数
            st[primes[j]*i]=1 # 将他们标为已经筛过了
            if(i%primes[j]==0): break
get_primes(n)
print(cnt)
 
'''
（1）对于 visit[i*prime[j]] = 1 的解释： 这里不是用i的倍数来消去合数，而是把 prime里面纪录的素数，升序来当做要消去合数的最小素因子。
（2）对于 i%prime[j] == 0 就break的解释 ：当 i是prime[j]的倍数时，i = kprime[j]，如果继续运算 j+1，i * prime[j+1] = prime[j] * k prime[j+1]，这里prime[j]是最小的素因子，当i = k * prime[j+1]时会重复，所以才跳出循环。
举个例子 ：i = 8 ，j = 1，prime[j] = 2，如果不跳出循环，prime[j+1] = 3，8 * 3 = 2 * 4 * 3 = 2 * 12，在i = 12时会计算。因为欧拉筛法的原理便是通过最小素因子来消除。
'''