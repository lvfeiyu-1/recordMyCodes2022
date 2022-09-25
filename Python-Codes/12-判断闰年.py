# 判断闰年

year=int(input("输入一个年份："))
if year%400==0 or (year%4==0 and year%100!=0):
    print("{0}年是闰年".format(year))
else:
    print("{0}年不是闰年".format(year))