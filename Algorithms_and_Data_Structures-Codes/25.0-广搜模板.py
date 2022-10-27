"""
1. 初始化队列
2. while queue不为空
3. 队顶元素出队
4. 遍历，满足条件的入队
"""
# def bfs():
#     queue = [1]
#     st[1] = True
#     d[1] = 0
#     while queue:
#         t = queue.pop(0)
#         if t not in graph: continue
 
#         for i in graph[t]:
#             if not st[i]:
#                 st[i] = True
#                 queue.append(i)
#                 if d[i]==-1:
#                     d[i] = d[t]+1
#     print(d[n])  

from queue import Queue

q=Queue(4)

q.put(1)
q.put(2)
q.put(3)

# empty: 检查队列是否为空，为空返回True，不为空返回False
print(q.empty())
# full: 判断队列是否已经满了
print(q.full())

print(q.qsize())
print(q.get()) #取到并弹出返回的值
print(q.get())
print(q.get())

print(q.empty())
print(q.full())


 