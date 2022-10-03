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
# 去除换行符,output为['-1', '2', '3'].<br>
# lines = [line.strip() for line in lines] <br>
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

