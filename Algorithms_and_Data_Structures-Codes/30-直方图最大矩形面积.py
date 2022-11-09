class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        ans=-1
        heights=[-1]+heights+[-1]
        n=len(heights)
        stack=[]

        for i in range(n):
            if not stack or heights[stack[-1]]<=heights[i]:
                stack.append(i)
            else:
                while heights[stack[-1]]>heights[i]:
                    h=heights[stack[-1]]
                    stack.pop()
                    left=stack[-1]
                    ans=max(ans,h*(i-left-1))
                stack.append(i)

        return ans

if __name__=='__main__':
    heights=[2,1,5,6,2,3]
    # heights=[2,4]
    ans=Solution.largestRectangleArea(Solution,heights)
    print(ans)