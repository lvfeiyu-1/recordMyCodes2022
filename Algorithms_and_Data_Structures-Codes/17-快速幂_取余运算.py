# 这个方法不能过全部数据，部分会超限
a,b,p=map(int,input().split())
base=a
ex=b
res=1
# print(a," ",b," ",p," ",res)
while b:
    if b&1:
        res=(res*a)%p
    a*=a
    b=b>>1
# print(a," ",b," ",p," ",res)
print("{}^{} mod {}={}".format(base,ex,p,res))

# 下面的方法能过
# 用python自带的pow函数速度比上面的快速幂代码快多了
a,b,p=map(int,input().split())
print("{}^{} mod {}={}".format(a,b,p,pow(a,b,p)))