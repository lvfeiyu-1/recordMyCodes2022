# 引入 datetime 模块
import datetime
def getYesterday(): 
    today=datetime.date.today() 
    oneday=datetime.timedelta(days=1) 
    yesterday=today-oneday  
    return yesterday
 
# 输出
print(getYesterday())


'''

import datetime

def getYesterday(): 
    yesterday = datetime.date.today() + datetime.timedelta(-1)
    return yesterday

print(getYesterday())

'''

