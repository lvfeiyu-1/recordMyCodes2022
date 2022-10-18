# n个数字的不同排列
from itertools import permutations
n=int(input())
s=[i for i in input().split()]
for p in permutations(s):
  print("".join(map(str,p)))
 
# n个字母的不同排列
str=list(input().split()) # 根据空格划分开
for p in permutations(str):
  print("".join(p))

'''
permutations只能对字符串、元组、列表、字典进行排列组合,不能对数字
所以你看到了上面对数字进行排列组合的时候,将数字迭代器转化为字符串
'''