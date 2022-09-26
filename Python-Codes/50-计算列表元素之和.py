# 计算列表元素之和  方法一
total=0
list1=[11,5,17,18,23]

for ele in range(0,len(list1)):
    total += list1[ele]

print("列表元素之和为：",total)


# 方法二   使用while()循环
total = 0
ele = 0
list1 = [11, 5, 17, 18, 23]  

while(ele<len(list1)):
    total+=list1[ele]
    ele+=1
print("列表元素之和为：",total)


# 方法三   使用递归
list1=[11,5,17,18,23]

def sumOfList(list,size):
    if(size==0):
        return 0
    else:
        return list[size-1]+sumOfList(list,size-1)
total = sumOfList(list1, len(list1))
print("列表元素之和为: ", total)


# 方法四  直接使用sum函数求解
list1 = [11, 5, 17, 18, 23]
print("列表元素之和为: ", sum(list1))


# 方法五  使用 reduce() 函数
from functools import reduce

list1 = [11, 5, 17, 18, 23]
sum=reduce(lambda x,y:x+y,list1)
print(sum)

''' 补充 reduce 函数知识点
在python3中, 内置函数中已经没有reduce了。要使用reduce, 需要从functools模块里引入
可以看到, reduce有三个参数, 第一个是函数function, 第二个是序列sequence, 第三个是initial, 为初始值, 默认为None
2、作用
对序列中的元素进行累积
3、返回值
返回函数的计算结果

4、例子
from functools import reduce

def add(x, y):
    return x + y

print(reduce(add, [1, 2, 3, 4, 5]))  #计算过程 ((((1 + 2) + 3) + 4) + 5)

# 运行结果
15


或者


from functools import reduce

print(reduce(lambda x, y: x + y, [1, 2, 3, 4, 5]))


或者


#有初始值的情况, 初始值为6
from functools import reduce

print(reduce(lambda x, y: x + y, [1, 2, 3, 4, 5], 6))

# 运行结果
21

#计算过程
6 + 1 = 7
7 + 2 = 9
9 + 3 = 12
12 + 4 = 16
16+ 5 = 21


'''