'''
二分搜索是一种在有序数组中查找某一特定元素的搜索算法。搜索过程从数组的中间元素开始，如果中间元素正好是要查找的元素，则搜索过程结束；
如果某一特定元素大于或者小于中间元素，则在数组大于或小于中间元素的那一半中查找，
而且跟开始一样从中间元素开始比较。如果在某一步骤数组为空，则代表找不到。这种搜索算法每一次比较都使搜索范围缩小一半。
'''

# 二分查找的前提是：已经有序了！

def binarySearch(arr,left,right,x):
    mid=int(left+(right-left)/2)
    if right >= 1:
        if arr[mid]==x:
            return mid
        elif arr[mid]>x:
            return binarySearch(arr,left,mid-1,x)
        elif arr[mid]<x:
            return binarySearch(arr,mid+1,right,x)
    else:
        return -1

arr=[2,3,4,10,50,61,72]
x=10

result=binarySearch(arr,0,len(arr)-1,x)

if result!=-1:
    print("元素在数组中的索引为 %d " % result)
else:
    print("元素不在数组中")

