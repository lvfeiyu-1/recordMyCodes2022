### 杂记一些知识点

1、谈谈 input() 函数

input函数：

（1）作用：接收来自用户的输入

（2）返回值类型：输入值的类型为str

（3）值的存储：使用=对输入的值进行存储


# 带提示的input（）函数及其常见问题

在初见input（）时，我发现了 variable = input(prompt)这个输入格式，一下子惊如天人。觉得Python的input（）函数的用户交互真是友善，从此不再需要再像其他一些编程语言一样单独写一个用户提示语。以下面一个片段为例：

但是，我很快在使用 variable = input(prompt) 这个形式时遇到了问题，当我理所当然的把input（prompt）中的prompt当作print（）函数使用时，我发现input（）并不能将变量赋值返回给程序。也就是说，如果我们在input（）的提示性语言中加入了变量，就很可能出错，例如：

name="Leo"
number=input('请输入',name,'同学的学号')  # 这会报错

那么这是不是意味着我们不能将变量加入其中呢？毕竟在很多循环中，提示性的语言是需要根据循环次数改变的。实际上我们是可以加入的，解决方法就是上面讲过的强制类型转换。需要注意的是，使用的符号是用于字符串连接的  “+”  而不是分割字符串和变量的  “,”

number=input('请输入'+str(name)+'同学的学号') 


# 利用input（）一次性输入多个变量值

我们在编程的时候，常常需要一次性给多个变量赋值。在C语言和C++中，我们使用scanf（"%d %d", &a,&b）这样的方式进行输入，其数据以空格为分界。那么在python中我们该如何一次性输入多个值呢？

（1）利用split（）函数进行输入，同时，我们不仅可以利用split（）函数一次性输入多个数，我们还可以设置分隔符，除了传统的空格形式，也可以用逗号“，”这种更符合语言习惯的方式分隔输入字符。其原理是因为input（)输入了一个字符串，而split（）函数能根据设定的分割点分割字符串并返回分割后的字符串列表，所以能实现一次性输入多个数据值。范例如下：

>>> a,b,c=input('以空格隔开：').split()
以空格隔开：1 2 3
>>> print(a,b,c)
1 2 3
>>> d,e,f=input('以逗号隔开：').split(",")
以逗号隔开：4,5,6
>>> print(d,e,f)
4 5 6
>>> 

但是，这样输入的值仍是字符串型，我们在上面已经说过字符串无法直接参与运算，最好输入时进行类型转换，那么，按照我们第二点的方法转换多输入值可行吗？

>>> d,e,f=int(input('以逗号隔开：').split(","))
以逗号隔开：1,2,3
Traceback (most recent call last):
  File "<pyshell#6>", line 1, in <module>
    d,e,f=int(input('以逗号隔开：').split(","))
TypeError: int() argument must be a string, a bytes-like object or a number, not 'list'
>>> 

可以看到，这样是不可以的，那么为什么上面单输入可以而多输入报错呢？原因我们其实已经说过了，split（）函数返回的是一个列表，spring当然能被转换成int型，但是列表是没法被这样直接转换的，所以我们需要用另一个函数map()来实现多输入的强制类型转换。

>>>>>>>>>>>>>>>>>>> 补充 map() 函数
map() 会根据提供的函数对指定序列做映射。第一个参数 function 以参数序列中的每一个元素调用 function 函数，返回包含每次 function 函数返回值的新列表。
语法：map(function, iterable, ...)
参数：function -- 函数； iterable -- 一个或多个序列
返回值：Python 2.x 返回列表。 Python 3.x 返回迭代器。
以下实例展示 map() 的用法：
>>> def square(x):
	return x**2

>>> map(square,[1,2,3,4,5])
#<map object at 0x000002A9A1CBE2E0> # 返回了迭代器
>>> list(map(square,[1,2,3,4,5]))
[1, 4, 9, 16, 25]
>>> list(map(lambda x: x**2,[1,2,3,4,5]))  #使用 lambda 匿名函数
[1, 4, 9, 16, 25]
>>> 
>>>>>>>>>>>>>>>>>>> 补充 map() 函数

我们将传入的函数设置为强制类型转换函数int，则split()函数返回的列表里的每一个值都将被强制转换类型，从而实现多输入的类型转换。范例如下：

>>> d,e,f=map(int,input('以逗号隔开：').split(","))
以逗号隔开：1,2,3
>>> print(type(d))
<class 'int'>
>>>



# 补充知识点：翻转函数
'''
  (1) reverse() 是python中列表的一个内置方法(在字典、字符串和元组中没有这个内置方法)，用于列表中数据的反转
      例子：
      lista = [1, 2, 3, 4]
      lista.reverse()
      print(lista)
      其实, lista.reverse()操作的返回值是一个None, 其作用的结果需要通过打印被作用的列表才可以查看出具体的效果

  (2) reserved() 是python内置函数之一, 其功能是对于给定的序列(包括列表、元组、字符串以及 range(n)区间),
      该函数可以返回一个逆序序列的迭代器(用于遍历该逆序序列)
      即：
      reverse(sequence) ->反转迭代器的序列值
      返回反向迭代器
      也就是说, 在经过reversed()的作用之后, 返回的是一个把序列值经过反转之后的迭代器, 所以需要通过遍历, 或者List或者next()等方法获取作用后的值
      
      reversed()函数的基本用法：
      #将列表进行逆序
      print([x for x in reversed([1,2,3,4,5])])
      #将元组进行逆序
      print([x for x in reversed((1,2,3,4,5))])
      #将字符串进行逆序
      print([x for x in reversed("abcdefg")])
      #将 range() 生成的区间列表进行逆序
      print([x for x in reversed(range(10))])
'''



# 补充知识点：reduce 函数
>>> from functools import reduce
>>> help(reduce)
Help on built-in function reduce in module _functools:

reduce(...)
    reduce(function, sequence[, initial]) -> value
    
    Apply a function of two arguments cumulatively to the items of a sequence,
    from left to right, so as to reduce the sequence to a single value.
    For example, reduce(lambda x, y: x+y, [1, 2, 3, 4, 5]) calculates
    ((((1+2)+3)+4)+5).  If initial is present, it is placed before the items
    of the sequence in the calculation, and serves as a default when the
    sequence is empty.
可以看到，reduce有三个参数，第一个是函数function，第二个是序列sequence，第三个是initial，为初始值，默认为None

2.作用
对序列中的元素进行累积
3.返回值
返回函数的计算结果
4.例子
（1）
from functools import reduce
from functools import reduce

def add(x, y):
    return x + y

print(reduce(add, [1, 2, 3, 4, 5]))  #计算过程 ((((1 + 2) + 3) + 4) + 5)

#运行结果
15

（2）
from functools import reduce
print(reduce(lambda x, y: x + y, [1, 2, 3, 4, 5]))

#运行结果
15

（3）
from functools import reduce
print(reduce(lambda x, y: x + y, [1, 2, 3, 4, 5], 6))

#运行结果
21
#计算过程
6 + 1 = 7
7 + 2 = 9
9 + 3 = 12
12 + 4 = 16
16+ 5 = 21