import calendar
monthRange=calendar.monthrange(2022,9)
print(monthRange)


# 执行以上代码输出结果为：
# (3, 30)
'''
输出的是一个元组，第一个元素是所查月份的第一天对应的是
星期几 (0-6), 第二个元素是这个月的天数。以上实例输出的意思为
 2022 年 9 月份的第一天是星期四，该月总共有 30 天。
'''