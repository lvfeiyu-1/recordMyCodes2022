# 通过用户输入数字计算阶乘

num=int(input("请输入一个数字："))
factorial=1

if num<0:
    print("抱歉，负数没有阶乘")
elif num==0:
    print("0的阶乘为 1")
else:
    for i in range(1,num+1):
        factorial*=i
    print("%d 的阶乘为 %d"%(num,factorial))
