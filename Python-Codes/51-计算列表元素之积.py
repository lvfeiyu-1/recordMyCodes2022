
def multiplyList(list):
    result=1
    for x in list:
        result*=x
    return result

list1 = [1, 2, 3]  
list2 = [3, 2, 4]
print(multiplyList(list1))
print(multiplyList(list2))

# 参考 第50题 的 reduce() 函数的讲解
from functools import reduce
list1 = [1,3,5,6,7]
sum = reduce(lambda x,y:x*y,list1)
print(sum)

# 采用递归的方法当然也行
def dfs(list,size):
    if size==0:
        return 1
    return list[size-1]+dfs(list,size-1)
list1 = [1,3,5,6,7]
list2=[x for x in range(3,6)]  #生成列表[3,4,5] 可惜这句话没用
print(dfs(list1))