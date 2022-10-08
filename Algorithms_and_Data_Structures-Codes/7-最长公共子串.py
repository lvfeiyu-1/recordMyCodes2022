MAXN=2020
def LCS(s1,s2):
    len1,len2=len(s1),len(s2)
    dp=[[0 for i in range(MAXN)] for j in range(MAXN)]
    maxLen=-1
    start=0
    for i in range(1,len1+1):
        for j in range(1,len2+1):
            if s1[i-1]==s2[j-1]:
                dp[i][j]=dp[i-1][j-1]+1
                if dp[i][j]>maxLen:
                    maxLen=dp[i][j]
                    start=i-maxLen
    # print(maxLen)
    print(s1[start:start+maxLen])
    if maxLen!=-1:        # 这里有个返回的坑 s[0:-1], 注意点！
        return s1[start:start+maxLen]
    return ""
    
    

if __name__=='__main__':
    n=int(input())
    lists=["" for i in range(n+2)]

    for i in range(1,n+1):
        lists[i]=input()

    s=""
    maxLen=-1
    s=LCS(lists[1],lists[2])
    for k in range(3,n+1):
        print("第{}个字符串是：".format(k),lists[k])
        s=LCS(s,lists[k])
    if maxLen<len(s):
        maxLen=len(s)

    # s=LCS(lists[n-1],lists[n])
    # for k in range(1,n-1):
    #     # print("第{}个字符串是：".format(k),lists[k])
    #     s=LCS(s,lists[k])
    # if maxLen<len(s):
    #     maxLen=len(s)
    
    # s=LCS(lists[1],lists[n])
    # for k in range(2,n):
    #     # print("第{}个字符串是：".format(k),lists[k])
    #     s=LCS(s,lists[k])
    # if maxLen<len(s):
    #     maxLen=len(s)

    print(maxLen)

# s=LCS(lists[1],lists[2])
# print(s)

# for i in range(1,n+1):
#     print(lists[i])

# # 字符串翻转

# # 普通翻转
# str='Runoob'
# print(str[::-1])

# # 使用 reversed()
# str='Runoob'
# print(''.join(reversed(str)))


# # reduce + lambda 反转法
# from functools import reduce

# str='Runoob'
# print(reduce(lambda x, y: y + x, str))