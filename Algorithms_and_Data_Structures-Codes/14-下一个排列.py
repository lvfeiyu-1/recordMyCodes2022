
nums=list(map(int,input().split()))   # 输入一个nums数组

n=len(nums)

for i in range(n-2,-1,-1):
    if nums[i]<nums[i+1]:
        for j in range(n-1,i,-1):
            if nums[j]>nums[i]:
                nums[i],nums[j]=nums[j],nums[i]
                break
        nums[i+1:]=sorted(nums[i+1:]) # sorted()不会改变原数组顺序
        break
    else:
        if i==0:
            nums.sort()  # sort()是会改变原数组顺序的

print(nums)


# 套力扣 python3 模板格式 (31. 下一个排列)
# 时间 48 ms，击败7.11%
# 内存 14.8 MB，击败91.19%
'''
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n=len(nums)

        for i in range(n-2,-1,-1):
            if nums[i]<nums[i+1]:
                for j in range(n-1,i,-1):
                    if nums[j]>nums[i]:
                        nums[i],nums[j]=nums[j],nums[i]
                        break
                nums[i+1:]=sorted(nums[i+1:]) # sorted()不会改变原数组顺序
                break
            else:
                if i==0:
                    nums.sort()  # sort()是会改变原数组顺序的
'''


