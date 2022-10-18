# 经力扣测试，该代码只能用于正整数，只能说这个模板的join太烂了，负数转字符再转回去会有bug
# 下面那个 def 定义的函数才是适用于整型的！
from itertools import permutations

nums=list(map(int,input().split())) # 1 2 3

res=[]
for p in permutations(nums):
    res.append(list(map(int,"".join(map(str,p)))))  # 显然join只能连接字符
    # res.append("".join(map(str,p)))  # [[], '123']

print(res)


# s=['1','2','3']
# print("".join(s))  # 123
# print("".join(s).split())  # ['123'], 即 split() 返回的是一个数组


# str="123"
# print(list(str)) # ['1', '2', '3']

'''
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res=[]
        from itertools import permutations
        for p in permutations(nums):
            res.append(list(p))
        return res
'''
