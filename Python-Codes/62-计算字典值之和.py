
def returnSum(myDict):
    sum=0
    for i in myDict:
        sum+=myDict[i]
    return sum

dict={'a':100,'b':200,'c':300}
print("Sum: ",returnSum(dict))



# 评论区
from functools import reduce

dict = {'a': 100, 'b':200, 'c':300} 
print(reduce(lambda x,y:x+y,dict.values()))



dict = {'a': 100, 'b':200, 'c':300}
print(sum(dict.values()))