# python中列表（或元组）与整数相乘  (注：全文用￥号代替>>>)
在Python中，可以将列表和元组与整数相乘。然后它将生成一个长度为l×n的列表或元组，长度为l给定列表/元组的长度。它将重复该集合中的元素，如：<br>
print([1,4,2,5]*3)<br>
[1, 4, 2, 5, 1, 4, 2, 5, 1, 4, 2, 5]<br>
ptint((1,4,2,5)*3)<br>
(1, 4, 2, 5, 1, 4, 2, 5, 1, 4, 2, 5)<br>
由于这里给定的列表是一个单例，因此我可以构造一个长度为n+1的列表，其中每个元素都是0，如下所示：<br>
print([0] * (5 + 1))<br>
[0, 0, 0, 0, 0, 0]<br>
当我将一个列表/元组与一个整数相乘时，项目的引用将被处理。因此，不会对值进行“深度复制”。因为int是不可变的，所以这并不重要。但如果元素是列表，则并没有复制该列表，而是创建了一个多次引用同一列表的列表。


# 利用input（）一次性输入多个变量值
我们在编程的时候，常常需要一次性给多个变量赋值。在C语言和C++中，我们使用scanf（"%d %d", &a,&b）这样的方式进行输入，其数据以空格为分界。那么在python中我们该如何一次性输入多个值呢？<br>

（1）利用split函数进行输入，同时，我们不仅可以利用split函数一次性输入多个数，我们还可以设置分隔符，除了传统的空格形式，也可以用逗号“，”这种更符合语言习惯的方式分隔输入字符。其原理是因为input输入了一个字符串，而split（）函数能根据设定的分割点分割字符串并返回分割后的字符串列表，所以能实现一次性输入多个数据值。范例如下：<br>
￥ a,b,c=input('以空格隔开：').split() <br>
以空格隔开：1 2 3 <br>
￥ print(a,b,c) <br>
1 2 3<br>
￥ d,e,f=input('以逗号隔开：').split(",")<br>
以逗号隔开：4,5,6<br>
￥ print(d,e,f)<br>
4 5 6<br>
￥ <br>

但是，这样输入的值仍是字符串型，我们在上面已经说过字符串无法直接参与运算，最好输入时进行类型转换，那么，按照我们第二点的方法转换多输入值可行吗？<br>
￥ d,e,f=int(input('以逗号隔开：').split(",")) <br>
以逗号隔开：1,2,3<br>
Traceback (most recent call last):<br>
  File "<pyshell#6>", line 1, in <module><br>
    d,e,f=int(input('以逗号隔开：').split(","))<br>
TypeError: int() argument must be a string, a bytes-like object or a number, not 'list'<br>
￥ 

可以看到，这样是不可以的，那么为什么上面单输入可以而多输入报错呢？原因我们其实已经说过了，split（）函数返回的是一个列表，spring当然能被转换成int型，但是列表是没法被这样直接转换的，所以我们需要用另一个函数map()来实现多输入的强制类型转换。<br>

￥￥￥ 补充 map() 函数 <br>
map() 会根据提供的函数对指定序列做映射。第一个参数 function 以参数序列中的每一个元素调用 function 函数，返回包含每次 function 函数返回值的新列表。<br>
语法：map(function, iterable, ...)<br>
参数：function -- 函数； iterable -- 一个或多个序列<br>
返回值：Python 2.x 返回列表。 Python 3.x 返回迭代器。<br>
以下实例展示 map() 的用法：<br>
￥ def square(x):<br>
       return x**2<br>
￥ map(square,[1,2,3,4,5])<br>
<map object at 0x000002A9A1CBE2E0> # 返回了迭代器<br>
￥ list(map(square,[1,2,3,4,5]))<br>
[1, 4, 9, 16, 25]<br>
￥ list(map(lambda x: x**2,[1,2,3,4,5]))  #使用 lambda 匿名函数<br>
[1, 4, 9, 16, 25]<br> 
￥￥￥ 补充 map() 函数<br>

我们将传入的函数设置为强制类型转换函数int，则split()函数返回的列表里的每一个值都将被强制转换类型，从而实现多输入的类型转换。范例如下：<br>
￥ d,e,f=map(int,input('以逗号隔开：').split(","))<br>
以逗号隔开：1,2,3<br>
￥ print(type(d))<br>
<class 'int'><br>
￥<br>


# python输入二维数组
下面是不导包的情况<br>
举例：dp=[[0]*MAXN for i in range(MAXN+1)]<br>


# Python中的输入：sys.stdin.readline()与input()
1、sys.stdin.readline() , input()的区别：<br>
<br>
首先 sys.stdin.readline() 和 input()都是以换行作为结束输入的标志，二者的区别就在于：<br>
sys.stdin.readline()会将标准输入全部获取，包括末尾的'\n'，而input()会把‘\n’忽略。<br>
<br>
import sys<br>
<br>
a = sys.stdin.readline()<br>
print(a, type(a))<br>
b = input()<br>
print(a)<br>
print(b)<br>
print(len(a), len(b))<br>
<br>

-1 2 3          # input,被sys.stdin.readline()读取.<br>
-1 2 3          # print(a, type(a)),显然换行符'\n'被读取了.不然<class 'str'>和-1 2 3 应该在同一行输出.<br>
 <class 'str'><br>
-1 2 3          # input,被input()读取.<br>
-1 2 3          # print(a),‘\n’被读取.<br>
<br>
-1 2 3          # print(b).<br>
7 6             # print(len(a), len(b)),空格3 + 字符3 + 换行符1 = 7.<br>
<br>
可以用sys.stdin.readline( ).strip( )去掉末尾的换行符。<br>


2、sys.stdin.readline(),sys.stdin.readlines(),sys.stdin.read()的区别<br>
显然之前readline()的代码由于换行符作为输入结束，所以是单行输入。如果想实现多行输入，需要用到while循环，win用control+Z(可以松手，也可以不松手),然后回车结束输入。<br>
import sys<br>
<br>
lines = []<br>
while True:<br>
    line = sys.stdin.readline().strip()<br>
    if not line:<br>
        break<br>
    lines.append(line)<br>
print(lines)<br>
<br>
输入输出：<br>
-1<br>
2<br>
3<br>
(control+z+enter)<br>
#output<br>
['-1', '2', '3']<br>
<br>
<br>
而sys.stdin.readlines()可以一次性读取多行数据，输出是含有str的list，会读出换行符等。<br>
同样的，control+D（Linus下）结束输入。<br>
<br>
import sys<br>
lines = sys.stdin.readlines()<br>
#去除换行符,output为['-1', '2', '3'].<br>
#lines = [line.strip() for line in lines] <br>
print(line)<br>
<br>
#input<br>
-1<br>
2<br>
3<br>
#output<br>
['-1\n', '2\n', '3\n']<br>
<br>
<br>
sys.stdin.read()也是多行读取，输出为str，不读换行符，换行符直接起作用。最后用control+D结束输入，其实是输入了一个空字符‘’，也会被读出来。<br>
<br>
import sys<br>
lines = sys.stdin.read()<br>
print(lines, type(lines))<br>
<br>
#input<br>
-1<br>
2<br>
3<br>
#output<br>
-1<br>
2<br>
3<br>
 <class 'str'><br>
<br>
#补充<br>
lines = lines.split('\n')<br>
<br>
#output<br>
['-1', '2', '3', ''] <class 'list'><br>


# python中sort()与sorted()的区别
1.主要区别<br>
(1) sort 是应用在 list 上的方法，而sorted 可以对所有可迭代的对象进行排序操作；<br>
(2) sort是对原有列表进行操作，而sorted返回的是一个新的可迭代对象，不会改变原来的对象；<br>
(3) sort使用方法为list.sort()， 而sorted的使用方法为sorted(list)<br>
(4) sorted语法:sorted(iterable=None,key=None,reverse=False)<br>
(5) sort语法:list.sort(key=None,reverse=False)，两个参数跟上面sorted的参数一样。在使用的时候要注意的是list.sort()没有返回值，也就是返回值为None。<br>
<br>
2.代码举例<br>
(1) sort——最简单的使用<br>
a = [2, 1, 5, 4]<br>
##reverse参数，对列表进行排序，True为从大到小排列， Fasle则为从小到大，默认为False<br>
a.sort()<br>
print(a)<br>
##[1, 2, 4, 5]<br>
a.sort(reverse=True)<br>
print(a)<br>
##[5, 4, 2, 1]<br>
<br>
(2) sort——使用key值进行排序<br>
a = [("a", 2), ("b", 1), ("c", 5), ("d", 4)]<br>
a.sort()<br>
print(a)<br>
##[('a', 2), ('b', 1), ('c', 5), ('d', 4)]<br>
##对于上面的类型，我们使用普通的排序方法，返回的值和原来一样，排序并没有生效，所有这里我们介绍另一种方法，key<br>
a = [("a", 2), ("c", 1), ("b", 5), ("d", 4)]<br>
a.sort(key=lambda x: x[1])<br>
print(a)<br>
##[('c', 1), ('a', 2), ('d', 4), ('b', 5)]<br>
<br>
(3) sort——综合使用<br>
a = [("a", 2), ("c", 1), ("b", 5), ("d", 4)]<br>
a.sort(key=lambda x: x[1])<br>
print(a)<br>
##[('c', 1), ('a', 2), ('d', 4), ('b', 5)]<br>
a.sort(key=lambda x: x[1], reverse=True)<br>
print(a)<br>
##[('b', 5), ('d', 4), ('a', 2), ('c', 1)]<br>
<br>
(4) sorted——不会改变原列表的顺序<br>
a = [2, 1, 5, 4]<br>
b = sorted(a)<br>
print(a)<br>
##[2, 1, 5, 4]<br>
print(b)<br>
##[1, 2, 4, 5]<br>
##这里我们可以发现a的值没有变化，但是b的值变的有序了<br>
<br>
(5) sorted——最简单的使用<br>
a = [2, 1, 5, 4]<br>
##reverse参数，对列表进行排序，True为从大到小排列， Fasle则为从小到大，默认为False<br>
b = sorted(a)<br>
print(b)<br>
##[1, 2, 4, 5]<br>
b = sorted(a, reverse=True)<br>
print(b)<br>
##[5, 4, 2, 1]<br>
<br>
(6) sorted——使用key值进行排序<br>
a = [("a", 2), ("c", 1), ("b", 5), ("d", 4)]<br>
##以第一个值进行排序<br>
b = sorted(a, key=lambda x: x[0])<br>
print(b)<br>
##[('a', 2), ('b', 5), ('c', 1), ('d', 4)]<br>
##以第二个值进行排序<br>
c = sorted(a, key=lambda x: x[1])<br>
print(c)<br>
##[('c', 1), ('a', 2), ('d', 4), ('b', 5)]<br>
<br>
(7) sorted——综合使用<br>
a = [("a", 2), ("c", 1), ("b", 5), ("d", 4)]<br>
b = sorted(a, key=lambda x: x[1])<br>
print(b)<br>
##[('c', 1), ('a', 2), ('d', 4), ('b', 5)]<br>
c = sorted(a, key=lambda x: x[1], reverse=True)<br>
print(c)<br>
##[('b', 5), ('d', 4), ('a', 2), ('c', 1)]<br>
<br>


# python堆栈
其实用列表实现即可<br>
<br>
栈（stack 堆栈），是一种容器，可存入数据元素、访问元素、删除元素，它的特点在于只能允许在容器的一端（称为栈顶端指标 top）进行加入数据（push）和输出数据（pop）的运算。没有了位置概念，保证任何时候可以访问、删除的元素都是此前最后存入的那个元素，确定了一种默认的访问顺序。<br>
<br>
补充一些题外话：
1、栈区（stack）— 由编译器自动分配释放 ，存放函数的参数值，局部变量的值等。其操作方式类似于数据结构中的栈。<br>
2、堆区（heap） — 一般由程序员分配释放， 若程序员不释放，程序结束时可能由OS回收 。注意它与数据结构中的堆是两回事，分配方式倒是类似于链表。<br>
3、全局区（静态区）（static）—，全局变量和静态变量的存储是放在一块的，初始化的全局变量和静态变量在一块区域，未初始化的全局变量和未初始化的静态变量在相邻的另一块区域。 - 程序结束后有系统释放 。<br>
4、文字常量区—常量字符串就是放在这里的。 程序结束后由系统释放。程序代码区—存放函数体的二进制代码。<br>
<br>
栈结构实现: 栈可以用顺序表实现，也可以用链表实现。<br>
栈的操作:<br>
Stack() 创建一个新的空栈<br>
push(item) 添加一个新的元素item到栈顶<br>
pop() 弹出栈顶元素<br>
peek() 返回栈顶元素<br>
is_empty() 判断栈是否为空<br>
size() 返回栈的元素个数<br>
<br>
代码如下：
<pre>
class Stack(object):
    """栈"""
    def __init__(self):
         self.items = []

    def is_empty(self):
        """判断是否为空""
        return self.items == []

    def push(self, item):
        """加入元素"""
        self.items.append(item)

    def pop(self):
        """弹出元素"""
        return self.items.pop()

    def peek(self):
        """返回栈顶元素"""
        return self.items[len(self.items)-1]

    def size(self):
        """返回栈的大小"""
        return len(self.items)
if __name__ == "__main__":
    stack = Stack()
    stack.push("hello")
    stack.push("world")
    stack.push("yake1965")
    print(stack.size())
    print(stack.peek())
    print(stack.pop())
    print(stack.pop())
    print(stack.pop())
</pre>


# python队列
队列是有序数据集合，队列的特点，删除数据项是在头部，称为前端(front)，增加数据在尾部，称为后端(rear)<br>
<br>
python其实自带队列的<br>
代码1:<br>
<pre>
'''导入队列'''
from queue import Queue

'''最多接收3个数据,设置队列长度'''
q = Queue(3)

'''这样子定义的话就是无限队列长度: q=Queue()'''

''' put 向队列中添加数据 '''
q.put(1)
q.put(2)
q.put(3)

'''获取当前队列长度'''
print(q.qsize())

'''取出最前面的一个数据 1 , 还剩两个'''
print(q.get())

'''再加入数据'''
q.put(4)

'''超过三个了.如果没有 timeout 参数会处于阻塞状态,卡在那边.若设置 2秒,2秒后会 raise 一个 FULL 的报错'''
q.put(5, timeout=2))

'''当然,也可以直接给个 block=False,强制设置为不阻塞(默认为会阻塞的)，一旦超出队列长度，立即抛出异常'''
q.put(6, block=False)

'''同样的,当取值(get)的次数大于队列的长度的时候就会产生阻塞，设置超时时间意为最多等待x秒，队列中再没有数据，就抛出异常.也可以使用block参数,跟上面一样'''
</pre>
其他常用方法：<br>
<pre>
empty: 检查队列是否为空，为空返回True，不为空返回False
full : 判断队列是否已经满了

join & task_done :
'''举例'''
from queue import Queue
q = queue.Queue(2)
q.put('a')
q.put('b')
'''程序会一直卡在下面这一行，只要队列中还有值，程序就不会退出'''
q.join()
-------------------------------------------------------------
q = queue.Queue(2)
q.put('a')
q.put('b')

q.get() 
q.get()
'''插入两个元素之后再取出两个元素，执行后发现，程序还是卡在下面的那个join代码'''
q.join()
-------------------------------------------------------------
q = queue.Queue(2)
q.put('a')
q.put('b')

q.get()
'''get取完队列中的一个值后，使用task_done方法告诉队列，我已经取出了一个值并处理完毕,下同'''
q.task_done() 
q.get()
'''在每次get取值之后，还需要在跟队列声明一下，我已经取出了数据并处理完毕，这样执行到join代码的时候才不会被卡住'''
q.task_done()
q.join()
</pre>
<br>
双向队列:<br>
但是删除列表的第一个元素（抑或是在第一个元素之前添加一个元素）之类的操作是很耗时的，因为这些操作会牵扯到移动列表里的所有元素。<br>
<br>
deque:<br>
collections.deque 类（双向队列）是一个线程安全、可以快速从两端添加或者删除元素的数据类型。而且如果想要有一种数据类型来存放“最近用到的几个元素”，deque 也是一个很好的选择。这是因为在新建一个双向队列的时候，你可以指定这个队列的大小，如果这个队列满员了，还可以从反向端删除过期的元素，然后在尾端添加新的元素。使用示例如下:<br>
<pre>
>>> from collections import deque
>>> dq = deque(range(10), maxlen=10) ➊
>>> dq
deque([0, 1, 2, 3, 4, 5, 6, 7, 8, 9], maxlen=10)
>>> dq.rotate(3) ➋
>>> dq
deque([7, 8, 9, 0, 1, 2, 3, 4, 5, 6], maxlen=10)
>>> dq.rotate(-4)
>>> dq
deque([1, 2, 3, 4, 5, 6, 7, 8, 9, 0], maxlen=10)
>>> dq.appendleft(-1) ➌
>>> dq
deque([-1, 1, 2, 3, 4, 5, 6, 7, 8, 9], maxlen=10)
>>> dq.extend([11, 22, 33]) ➍
>>> dq
deque([3, 4, 5, 6, 7, 8, 9, 11, 22, 33], maxlen=10)
>>> dq.extendleft([10, 20, 30, 40]) ➎
>>> dq
deque([40, 30, 20, 10, 3, 4, 5, 6, 7, 8], maxlen=10)
<br>
❶ maxlen 是一个可选参数，代表这个队列可以容纳的元素的数量，而且一旦设定，这个属性就不能修改了。

❷ 队列的旋转操作接受一个参数 n，当 n > 0 时，队列的最右边的n 个元素会被移动到队列的左边。当 n < 0 时，最左边的 n 个元素会被移动到右边。

❸ 当试图对一个已满（len(d) == d.maxlen）的队列做尾部添加操作的时候，它头部的元素会被删除掉。注意在下一行里，元素 0 被删除了。

❹ 在尾部添加 3 个元素的操作会挤掉 -1、1 和 2。

❺ extendleft(iter) 方法会把迭代器里的元素逐个添加到双向队列的左边，因此迭代器里的元素会逆序出现在队列里。
</pre>
Python提供的所有队列类型：<br>
先进先出队列 queue.Queue<br>
后进先出队列 queue.LifoQueue (Queue的基础上进行的封装)<br>
优先级队列 queue.PriorityQueue (Queue的基础上进行的封装)<br>
双向队列 queue.deque<br>
除了上述提到的队列与双端队列,还有两个用的比较少的:后进先出队列与优先级队列<br>


# python中定义（声明）结构体(验证过了，很好用)
前言：<br>
在Python中并无像C/C++那样的结构体类型，但是由于Python是用C编写而来的，很多东西可以互通。<br>
Python是有struct模块，但并非是用于处理一般结构体的，并且使用起来也比较麻烦。<br>
<br>
实现：<br>
我们可以使用Class类来实现一个在C/C++中呈现的结构体，也可以实现C/C++中typedef struct {}的方法。<br>
<pre>
'''首先定义一个类，要有__init__'''
class SN:
    def __init__(self):
        self.data = ""
        self.datalen = ""
        self.datatype = ""

'''开始初始化结构体'''
a = SN()
a.data = "233333"
a.datalen = len(a.data)
a.datatype = type(a.data)

print(
    f"a.data: {a.data}\n"
    f"a.datalen: {a.datalen}\n"
    f"a.datatype: {a.datatype}\n"
)
</pre>
这样定义完一个类之后，已经是相当于typedef struct了<br>
如果你不理解为什么是这样，那么我用C的写法给你写一遍你就明白了。<br>
<pre>
typedef struct {
    char *data;
    int   datalen;
    int   datatype;
} SN;

struct SN *a = (SN *)malloc(sizeof(SN));
a->data = "233333";
a->datalen = strlen(a->data);
a->datatype = 1;
</pre>


# Python IDLE常用快捷键
<pre>
F1                  打开Python帮助文档                  Python文件窗口和Shell 均可用
Alt+P               浏览历史命令（上一条）                  仅 Python Shell 窗口可用
Alt+N	            浏览历史命令（下一条）	                仅 Python Shell 窗口可用
Alt+/	            自动补全前面曾经出现过的单词，如果之前有多个单词具有相同前缀，可以连续按下该快捷键，在多个单词中间循环选择	                    Python文件窗口和Shell窗口均可用
Alt+3	            注释代码块	                  仅 Python 文件窗口可用
Alt+4	            取消代码块注释	                    仅 Python 文件窗口可用
Alt+g	            转到某一行	                     仅 Python 文件窗口可用
Ctrl+Z	            撤销一步操作	                Python 文件窗口和 Shell 窗口均可用
Ctrl+Shift+Z	    恢复上—次的撤销操作	                Python 文件窗口和 Shell 窗口均可用
Ctrl+S	            保存文件	                            Python              文件窗口和                  Shell 窗口均可用
Ctrl+]	            缩进代码块	                仅 Python 文件窗口可用
Ctrl+[	            取消代码块缩进	             仅 Python 文件窗口可用
Ctrl+F6	            重新启动 Python Shell	        仅 Python Shell 窗口可用
</pre>
