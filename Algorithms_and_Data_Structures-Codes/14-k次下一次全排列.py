class Solution:
    def next_permulation(self,nums)->None:
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

if __name__=='__main__':
    n=int(input())
    m=int(input())
    nums=list(map(int,input().split()))   # 输入一个nums数组
    for _ in range(m):
        Solution.next_permulation(Solution,nums)
    
    l=len(nums)
    for i in range(l-1):
        print(nums[i],end=" ")
    print(nums[l-1],end="")