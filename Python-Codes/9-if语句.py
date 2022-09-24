# 用户输入数字

num=float(input('输入一个数字：'))

if num>0:
    print('正数')
elif num==0:
    print('零')
else:
    print('负数')

# 当然我们也可以使用内嵌 if 语句来实现：

num = float(input("输入一个数字: "))
if num >= 0:
   if num == 0:
       print("零")
   else:
       print("正数")
else:
   print("负数")