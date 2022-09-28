# 其实啊这个什么时间戳，我不是很懂啊，记不住主要是

# 实例1
import time
import datetime
 
# 先获得时间数组格式的日期
threeDayAgo = (datetime.datetime.now() - datetime.timedelta(days = 3))
# 转换为时间戳
timeStamp = int(time.mktime(threeDayAgo.timetuple()))
# 转换为其他字符串格式
otherStyleTime = threeDayAgo.strftime("%Y-%m-%d %H:%M:%S")
print(otherStyleTime)


# 实例2
import time
import datetime
 
#给定时间戳
timeStamp = 1557502800
dateArray = datetime.datetime.utcfromtimestamp(timeStamp)
threeDayAgo = dateArray - datetime.timedelta(days = 3)
print(threeDayAgo)




# 评论区说这个更加简洁
import datetime
threeDayAgo = datetime.datetime.today() - datetime.timedelta(3)
print(threeDayAgo)
otherStyleTime = threeDayAgo.strftime("%Y-%m-%d %H:%M:%S")
print(otherStyleTime)