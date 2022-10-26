M=int(input())

s=[0 for _ in range(M+2)]

for i in range(1,M+1):
    s[i]=s[i-1]+i  # 构造前缀和数组

for i in range(1,M):
    for j in range(i+1,M+1):
        if s[j]-s[i-1]==M:
            print("{} {}".format(i,j))