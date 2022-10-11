# 思路:判断所有子串是否为回文子串,选出最长的
# 一、状态定义:
# dp[i][j]表示s[i:j+1]是否为回文子串(这里+1是为了构造闭区间)
# 二、状态转移方程:
#    1当前ij状态:头尾必须相等(s[i]==s[j]) ==> 过去ij状态:去掉头尾之后还是一个回文(dp[i+1] [j-1] is True)
#    2边界条件:
#    1)只要是找过去ij状态的时候,就会涉及边界条件(即超出边界情况处理):
#      边界j-1-(i+1)<=0 ==> 即当j-i<=2 + 当s[i]==s[j]时,一定是回文串
#    2)当i==j时,指一个字符,一定是回文
# 三、输出内容:
#	dp[i] [j]为截取的子串,每次发现新回文都比较一下长度j-i+1,更新起始位置i与最大的长度


class Solution:
    def longestPalindrome(self,s:str)->str:
        n=len(s)
        if n<2:
            return s
        
        dp=[[False]*n for _ in range(n)]
        max_len=1
        index=0

        for i in range(n):
            dp[i][i]=True   # 每个字符本身就是一个回文串
        
        for j in range(1,n):  # 遍历字符串的第一位到最后一位
            for i in range(j):  # 遍历当前位字符的前面所有字符,说多一句，这个双重循环遍历方式和最长上升子序列的遍历方式很相似
                if s[i]==s[j]:
                    if j-i<=2:
                        dp[i][j]=True
                    else:
                        dp[i][j]=dp[i+1][j-1]

                if dp[i][j]==True:
                    curlen=j-i+1
                    if curlen>max_len:
                        max_len=curlen
                        index=i

        # for i in range(n):
        #     for j in range(n):
        #         print(dp[i][j],end=" ")
        #     print("")
        return s[index:index+max_len]

if __name__=='__main__':
    s=str(input())
    # print(s)
    s=Solution.longestPalindrome(Solution,s)  # 原来是如此传参
    print(len(s))