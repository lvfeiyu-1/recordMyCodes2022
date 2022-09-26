# 定义立方和的函数

def sumOfSeries(n):
    sum=0
    for i in range(1,n+1):
        sum+=i**3
    return sum

#调用函数
# n=7
n=int(input("请输入一个正整数："))
print(sumOfSeries(n))