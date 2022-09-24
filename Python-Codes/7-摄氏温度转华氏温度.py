# 用户输入摄氏温度 ( 1 摄氏度等于 33.8 华氏度)

# 接收用户输入
celsius = float(input('输入摄氏温度: '))

# 计算华氏温度
fahrenheit = (celsius * 1.8) + 32
print('%0.1f 摄氏温度转为华氏温度为 %0.1f ' % (celsius, fahrenheit))

# 以上实例中，摄氏温度转华氏温度的公式为
# celsius * 1.8 = fahrenheit - 32。所以得到以下式子：

# celsius = (fahrenheit - 32) / 1.8