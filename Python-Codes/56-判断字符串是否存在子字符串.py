
def check(string,sub_str):
    if(string.find(sub_str)!=-1):
        print("存在！")
    else:
        print("不存在！")

string="www.runoob.com"
sub_str="runoob"
check(string,sub_str)

# 另法

string = "www.runoob.com"
sub_str ="runoob"
if sub_str in string:
    print("存在")
else:
    print("不存在")