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
由于join的原因,第一个print需要把数字转化为字符,因为join只能把字符连接起来
'''