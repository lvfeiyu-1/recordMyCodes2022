#输入一个列表

# split()：拆分字符串。
# 通过指定分隔符对字符串进行切片，并返回分割后的 字符串列表（list）
a=input('列表:').split(",")
print(a,type(a))
a1=[int(a[i]) for i in range(len(a))]
print(a1,type(a1))

s= 'www.dod.com.cn'
# 默认分隔符
print(s.split())
#  . 分割
print(s.split('.'))
#  分割一次   2次
#  print(s.split('.',1))
#  print(s.split('.',2))

'''
python的input()会自动的将输入的数据转化为字符串
所以我们如何输入列表呢？

在这里我们可以使用eval()函数, eval简单来说可以
去掉参数的最外侧的引号并执行余下语句的函数。
'''
#记得是输入列表的形式哦！！！！
a=input()
print(a,type(a))

a=eval(input())
print(a,type(a))




# 输入一个元组

# 输入一组元组
tup = tuple(map(int, input().split(' ')))
# 输入多组元组
n=5
arr = [tuple(map(int, input().split(' '))) for i in range(n)]


