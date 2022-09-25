# 获取用户输入十进制数

dec=int(input('输入数字：'))

print("十进制数为：",dec)
print("转换为二进制数为：",bin(dec))
print("转换为八进制数为：",oct(dec))
print("转换为十六进制为：",hex(dec))



# 别人在笔记区补充

#十进制到二进制：
def dec2bin(num):
    l = []
    if num < 0:
        return '-' + dec2bin(abs(num))
    while True:
        num, remainder = divmod(num, 2)
        l.append(str(remainder))
        if num == 0:
            return ''.join(l[::-1])

# 十进制到八进制：
def dec2oct(num):
    l = []
    if num < 0:
        return '-' + dec2oct(abs(num))
    while True:
        num, remainder = divmod(num, 8)
        l.append(str(remainder))
        if num == 0:
            return ''.join(l[::-1])

# 十进制到十六进制：
base = [str(x) for x in range(10)] + [ chr(x) for x in range(ord('A'),ord('A')+6)]
def dec2hex(num):
    l = []
    if num < 0:
        return '-' + dec2hex(abs(num))
    while True:
        num,rem = divmod(num, 16)
        l.append(base[rem])
        if num == 0:
            return ''.join(l[::-1])


