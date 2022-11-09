
'''
# 最后一个样例时间超限了, 9/10
N=int(input())
H=[]

for i in range(N):
    H.append(int(input()))

stack=[]

for i in range(N):
    stack.append(H[i])
    top=len(stack)-1
    for j in range(i+1,N):
        if stack[top]>H[j]:
            stack.append(H[j])
        elif stack[top]<H[j]:
            stack.pop()
            top-=1
            if top==-1:
                print(j+1)
                break
            while stack[top]<H[j]:
                stack.pop()
                top-=1
                if top==-1:
                    print(j+1)
            if stack.count()==0:
                break
        if j==N-1:
            print(0)
    if i==N-1:
        print(0)
    stack.clear()
'''
# 参考题解思路，自己写逆向单调递减栈
N=int(input())
H=[0]*(N+1)
ans=[0]*(N+1)
stack=[]

for i in range(N):
    H[i]=int(input())

for i in range(N-1,-1,-1):
    while stack and H[stack[-1]]<=H[i]:
       stack.pop()
    if not stack:
        ans[i]=0
    else:
        ans[i]=stack[-1]+1
    stack.append(i)

for i in range(N):
    print(ans[i])
