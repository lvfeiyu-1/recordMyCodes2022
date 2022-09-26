# 方法一
'''
补充知识点：
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
def Reverse1(list):
    return [ele for ele in reversed(list)]

List=[10,11,12,13,14,15]
print(Reverse1(List))


# 方法二
def Reverse2(list):
    list.reverse()
    return list

List=[10,11,12,13,14,15]
print(Reverse2(List))


# 方法三
def Reverse3(list):
    new_list=list[::-1]
    return new_list

List=[10,11,12,13,14,15]
print(Reverse3(List))


# 还可以这样子做
# 还可以直接调用 list 列表的 sort 方法, 
# 设置 reverse 为 True 即可翻转列表：
li = [*range(10, 16)]
# 得到列表 li = [10, 11, 12, 13, 14, 15], * 为解包符号
print(li)

# 降序排列
li.sort(reverse = True)
print(li)
# 输出: [15, 14, 13, 12, 11, 10]


# 也可以这样子做
# 利用 while 循环:
def fanzhuan(list): 
    a=[]
    i=len(list)
    while i>0:
         a.append(list[i-1]) #生成一个新的列表，原列表的最后一位成为第一位
         i-=1 #依次向前进一位
    return a
fa=fanzhuan([34,12,54,234,65,122])
print(fa)

