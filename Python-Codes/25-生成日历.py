# 引入日历模块

import calendar

yy=int(input("请输入年份："))
mm=int(input("请输入月份："))

# 输出整一个月份
print(calendar.month(yy,mm))