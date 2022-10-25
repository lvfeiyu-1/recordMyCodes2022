import math # 无脑调库解决
m,n=map(int,input().split())
 
_gcd=math.gcd(m,n)  # 最大公约数
# _lcm=math.lcm(m,n)  # 最小公倍数
# 但在python3中是没有这个lcm函数的，所以求最小公倍数最好用最大公约数求，以防编译不过的情况
 
# print("{} {}".format(_gcd,_lcm))
print("{} {}".format(_gcd,m*n//_gcd))