# enen
str="runoob"
print(len(str))

# 使用循环
def findLen(str):
    counter=0
    while str[counter:]:
        counter+=1
    return counter

str = "runoob"
print(findLen(str))

# 评论区
def length(src):
    # 字符串长度
    count = 0
    all_str = src[count:]

    for _ in all_str:
        count += 1

    print("字符串长度为: %s" % count)

src = "Runoob"
length(src)
