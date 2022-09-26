test_str = "Runoob"
 
# 输出原始字符串
print ("原始字符串为 : " + test_str)
# 移除第三个字符 n
new_str = ""
for i in range(0,len(test_str)):
    if i!=2:
        new_str+=test_str[i]
print ("字符串移除后为 : " + new_str)

# help(str.replace)

''' 补充replace的用法
用命令 help(str.replace) 查看解释：

Help on method_descriptor:

replace(self, old, new, count=-1, /)
    Return a copy with all occurrences of substring old replaced by new.
    
      count
        Maximum number of occurrences to replace.
        -1 (the default value) means replace all occurrences.
    
    If the optional argument count is given, only the first count occurrences are
    replaced.


replace(self, old, new, count=-1, /),
这个就是replace的基本用法,old就是指要替换的字符串,
new就是产生的新的字符串,
count是替换的次数, 如果指定第三个参数max
则替换次数不超过max次 (将旧的字符串用心的字符串替换不超过max次).

'''

test_str = "Runoob"
new_str = test_str.replace(test_str[2], "", 1)
print(new_str)



# 另法，逻辑懂了，但代码可能有错（评论区写的）

str = 'Runoob'

'''
@param str 原字符串
@paramnum 要移除的位置
@return 移除后的字符串
'''

def ff(str,num):
    return str[:num] + str[num+1:];
print(ff(str,2))
print(ff(str,4))

