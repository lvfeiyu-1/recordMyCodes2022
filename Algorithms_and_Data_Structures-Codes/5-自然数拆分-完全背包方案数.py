# 完全背包方案数一维
N=int(input())

dp=[0 for i in range(N+2)]
dp[0]=1

for i in range(1,N):
    for j in range(i,N+1):
        dp[j]+=dp[j-i]

print(dp[N])

#完全背包方案数二维
# N=int(input())
# dp=[[0]*(N+2) for i in range(N+2)]
# dp[0][0]=1  # 这个初始化有意思的啊

# for i in range(1,N):
#     for j in range(N+1):
#         if j<i:      # 曾经我漏了处理这个条件而折腾了很久，心酸啊！一维才有可能不用处理这个条件
#             dp[i][j]=dp[i-1][j]   
#         else:
#             dp[i][j]=(dp[i-1][j]+dp[i][j-i])%2147483648   # 把取模放到这个地方才可AC，放到下面输出的位置会“内存限制超限”(无法理解，可能下面是已经爆int了) 

# print(dp[N-1][N])



## 没有理解二维怎么弄的
# MAXN=4010
# dp=[[0]*MAXN for i in range(MAXN)]

# N=int(input())

# for i in range(N+1):
#     dp[1][i]=1

# for i in range(2,N+1):
#     for j in range(N+1):
#         dp[i][j]=dp[i-1][j]
#         if j>=i:
#             for k in range(1,j//i+1):
#                 dp[i][j]+=dp[i-1][j-k*i]

# # print(dp[N][N])
# print((dp[N][N]-1)%2147483648u)

# 输入   这个例子二维python跑还会时间超限，但是下面的C++则能过
# 2737
# 输出
# 1691770120
# 标准答案
# 1691770120


# #include<iostream>
# using namespace std;

# //【重要】f[i][j]表示i个数的和为j的可能性
# //如果选择第i个数，相当于选择值i。
# const int N = 4010;
# unsigned f[N][N];
# int main() {
#     int n;
#     cin >> n;
#     for (int j = 0; j <= n; j++) f[1][j] = 1;
#     for (int i = 2; i <= n; i++) {
#         for (int j = 0; j <= n; j++) {
#             f[i][j] = f[i - 1][j];
#             if (j >= i)
#                 for (int k = 1; k * i <= j; k++)
#                     f[i][j] += f[i - 1][j - k * i];
#         }
#     }
#     cout << (f[n][n] - 1) % 2147483648u << endl;
#     return 0;
# }
