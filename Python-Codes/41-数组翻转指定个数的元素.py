
'''
定义一个整型数组，并将指定个数的元素翻转到数组的尾部。
例如：(ar[], d, n) 将长度为 n 的 数组 arr 的前面 d 个元素
翻转到数组尾部。以下演示了将数组的前面两个元素放到数组后面。
原始数组:
1 2 3 4 5 6 7
翻转后:
3 4 5 6 7 1 2
'''

# 实例 1
def leftRotate(arr,d,n):
    for i in range(d):
        leftRotatebyOne(arr,n)

def leftRotatebyOne(arr,n):
    temp=arr[0]
    for i in range(n-1):
        arr[i]=arr[i+1]
    arr[n-1]=temp

def printArray(arr,size):
    for i in range(size):
        print("%d"%arr[i],end=" ")

arr=[1,2,3,4,5,6,7]
leftRotate(arr,2,7)
printArray(arr,7)


# 实例 2     说实话，这个逻辑我没看懂
def leftRotate(arr, d, n):
    for i in range(gcd(d,n)):
         
        temp = arr[i]
        j = i
        while 1:
            k = j + d
            if k >= n:
                k = k - n
            if k == i:
                break
            arr[j] = arr[k]
            j = k
        arr[j] = temp

def printArray(arr, size):
    for i in range(size):
        print ("%d" % arr[i], end=" ")

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)

arr = [1, 2, 3, 4, 5, 6, 7]
leftRotate(arr, 2, 7)
printArray(arr, 7)


# 实例 3      说实话，这个逻辑我也没看懂
def rverseArray(arr, start, end):
    while (start < end):
        temp = arr[start]
        arr[start] = arr[end]
        arr[end] = temp
        start += 1
        end = end-1
 
def leftRotate(arr, d):
    n = len(arr)
    rverseArray(arr, 0, d-1)
    rverseArray(arr, d, n-1)
    rverseArray(arr, 0, n-1)
 
def printArray(arr):
    for i in range(0, len(arr)):
        print (arr[i], end=' ')
 
arr = [1, 2, 3, 4, 5, 6, 7]
leftRotate(arr, 2)
printArray(arr)

