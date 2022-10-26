n,p=map(int,input().split())

a=[0 for _ in range(5000002)]
d=[0 for _ in range(5000002)]

line=list(map(int,input().split()))

for i in range(1,n+1):
    a[i]=line[i-1]

d[1]=a[1]
for i in range(2,n+1):
    d[i]=a[i]-a[i-1]

for _ in range(p):
    x,y,z=map(int,input().split())
    d[x]+=z
    d[y+1]-=z

min=d[1]
for i in range(2,n+1):
    d[i]+=d[i-1]
    if d[i]<min:
        min=d[i]

print(min)

# print(d[1]," ",a[1]) # 经测试，这样会输出三个空格
# print("{} {}".format(d[1],a[1]))

# n,p=map(int,input().split())

# d=[0]

# line=[0]+list(map(int,input().split()))
# # line.reverse()

# # a,b=line.pop(0),0
# # line.pop(0)
# d.append(line[1])
# # d.append(line.pop())
# for i in range(2,n+1):
#     a,b=line[i-1],line[i]
#     d.append(b-a)
#     # a = line.pop()
#     # b = line.pop()
#     # d.append(a-b)

# # d.append(0)
# # d.append(0)

# for _ in range(p):
#     x,y,z=map(int,input().split())
#     d[x]+=z
#     d[y+1]-=z

# min=d[1]
# for i in range(2,n+1):
#     d[i]+=d[i-1]
#     if d[i]<min:
#         min=d[i]

# print(min)

# print(d[1]," ",a[1]) # 经测试，这样会输出三个空格
# print("{} {}".format(d[1],a[1]))