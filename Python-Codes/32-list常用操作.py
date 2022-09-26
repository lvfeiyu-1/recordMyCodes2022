li=["a",'b','mpilgrim','z','example']
print(li)
print(li[1])

#索引   左闭右开
print("")
print(li[-1])
print(li[-3])

print(li[1:3])
print(li[1:-1])
print(li[0:3])

# list 增加元素
print("")
li.append("new")
print(li)
li.insert(2,"new")
print(li)
li.extend(["two","elements"])
print(li)

# list搜索
print("")
print(li)
print(li.index("example"))
print(li.index("new"))
# print(li.index("c"))
# print("c" in li)

# list运算符
print("")
li = ['a', 'b', 'mpilgrim']
li = li + ['example', 'new']
print(li)
li += ['two']   
print(li)
li = [1, 2] * 3
print(li)

# 使用join链接list成为字符串
print("")
params = {"server":"mpilgrim", "database":"master", "uid":"sa", "pwd":"secret"}
print(["%s=%s" % (k, v) for k, v in params.items()])
print(";".join(["%s=%s" % (k, v) for k, v in params.items()]))
# join 只能用于元素是字符串的 list; 它不进行任何的类型强制转换。
# 连接一个存在一个或多个非字符串元素的 list 将引发一个异常。

# list 分割字符串
print("")
li = ['server=mpilgrim', 'uid=sa', 'database=master', 'pwd=secret']
s = ";".join(li)
print(s)
print(s.split(";"))
print(s.split(";",1))
'''
split 与 join 正好相反, 它将一个字符串分割成多元素 list。
注意, 分隔符 (";") 被完全去掉了, 它没有在返回的 list 中的任意元素中出现。
split 接受一个可选的第二个参数, 它是要分割的次数。
'''

# list 的映射解析
print("")
li = [1, 9, 8, 4]
print([elem*2 for elem in li])
print(li)
li = [elem*2 for elem in li]
print(li)

# dictionary 中的解析
print("")
params = {"server":"mpilgrim", 
         "database":"master", "uid":"sa", "pwd":"secret"}
print(params.keys())
print(params.values())
print(params.items())
print([k for k, v in params.items()])
print([v for k, v in params.items()])
print(["%s=%s" % (k, v) for k, v in params.items()])

# list 过滤
li = ["a", "mpilgrim", "foo", "b", "c", "b", "d", "d"]
print([elem for elem in li if len(elem) > 1])
print([elem for elem in li if elem != "b"])
print([elem for elem in li if li.count(elem) == 1])

print("")