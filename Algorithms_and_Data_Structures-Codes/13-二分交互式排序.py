# Forward declaration of compare API.
# def compare(a, b):
# @param a, b int
# @return bool
# return bool means whether a is less than b.

def compare(a:int,b:int):
    return a>b

class Solution(object):
    def specialSort(self, N):
        """
        :type N: int
        :rtype: List[int]
        """
        res=[1]
        for i in range(2,N+1):
            left=0
            right=len(res)-1
            while(left<=right):
                mid=left+right>>1
                if compare(res[mid],i):
                    left=mid+1
                else:
                    right=mid-1
            res.append(i)
            for i in range(len(res)-1,left,-1):
                res[i],res[i-1]=res[i-1],res[i]
        print(res)
