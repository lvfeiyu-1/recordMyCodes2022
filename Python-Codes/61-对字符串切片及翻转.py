
def rotate(input,d):
    Lfirst=input[0:d]
    Lsecond=input[d:]
    Rfirst=input[0:len(input)-d]
    Rsecond=input[len(input)-d:]

    print("头部切片翻转：",(Lsecond+Lfirst))
    print("尾部切片翻转：",(Rsecond+Rfirst))

if __name__=="__main__":
    input='Runoob'
    d=2 #截取两个字符串
    rotate(input,d)

'''
执行以上代码输出结果为：
    头部切片翻转 :  noobRu
    尾部切片翻转 :  obRuno
'''