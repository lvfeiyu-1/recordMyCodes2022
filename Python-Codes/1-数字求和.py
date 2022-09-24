#用户输入数字
num1=input('输入第一个数字：')
num2=input('输入第二个数字：')

# 使用了内置函数 input() 来获取用户的输入，
# input() 返回一个字符串，所以我们需要使用 float() 方法将字符串转换为数字。

#求和
sum=float(num1)+float(num2)

#显示计算结果
print('数字 {0} 和 {1} 相加结果为： {2}'.format(num1, num2, sum))

#或者
print('两数之和为 %.1f'%(float(input('输入第一个数字：'))+\
                         float(input('输入第二个数字：'))))