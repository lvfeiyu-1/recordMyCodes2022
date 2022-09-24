
x=input('输入x值：')
y=input("输入y值：")

tmp=x
x=y
y=tmp

print("交换后 x 的值为：{}".format(x))
print("交换后 y 的值为：{}".format(y))

# 还有一种非常优雅的方式来 交换变量， 不用设立临时变量

x,y = y,x
print("又交换后 x 的值为：{}".format(x))
print("又交换后 y 的值为：{}".format(y))

