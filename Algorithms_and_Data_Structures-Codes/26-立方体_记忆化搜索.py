
f=[0]*10
_f=[-1]*10

print(f)
print(_f)
print("")

# f=_f # 这样子是浅拷贝，改f会把_f也给改了

# print(f)
# print(_f)
# print("")

# f[0],f[1]=2,2
# print(f)
# print(_f)

import copy
f=copy.deepcopy(_f)

f[0],f[1]=2,2
print(f)
print(_f)
print("")
