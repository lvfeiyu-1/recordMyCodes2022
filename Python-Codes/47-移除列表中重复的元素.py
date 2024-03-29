# 方法一
'''
补充知识点：
(1) 集合(set)是一个无序的不重复元素序列。
(2) 列表是一种数据项构成的有限序列，即按照一定的线性顺序排列而成的数据项的集合，
    在这种数据结构上进行的基本操作包括对元素的的查找、插入和删除。
'''
list_1 = [1,2,1,4,6]
print(list(set(list_1)))


# 删除两个列表中重复的元素
list_1 = [1, 2, 1, 4, 6]
list_2 = [7, 8, 2, 1]

print(list(set(list_1) ^ set(list_2)))

'''
首先，使用 set() 将两个列表转换为两个集合，用于删除列表中的重复元素。

然后，使用 ^ 运算符得到两个列表的对称差。
执行以上代码输出结果为：
'''