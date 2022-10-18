
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res=[]
        from itertools import permutations
        for p in permutations(nums):
            if list(p) not in res:
                res.append(list(p)) # 需要去重，去重方法有很多
        return res