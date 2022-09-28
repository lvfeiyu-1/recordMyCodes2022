# 字符串翻转

# 普通翻转
str='Runoob'
print(str[::-1])

# 使用 reversed()
str='Runoob'
print(''.join(reversed(str)))


# reduce + lambda 反转法
from functools import reduce

str='Runoob'
print(reduce(lambda x, y: y + x, str))