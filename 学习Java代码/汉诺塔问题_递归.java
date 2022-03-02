/**
    汉诺塔（又称河内塔）问题是源于印度一个古老传说的益智玩具。
    大梵天创造世界的时候做了三根金刚石柱子， 在一根柱子上从下往上按照大小顺序摞着 64 片圆盘。
    大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一 根柱子上。并且规定，在小圆盘上不能放大圆盘，
    在三根柱子之间一次只能移动一个圆盘。
*/

//public class HanoiTower {
public class exercise {

    //编写一个 main 方法
    public static void main(String[] args) {
        Tower tower = new Tower();
        tower.move(4, 'A', 'B', 'C');
    }
}

class Tower {
    // 方法
    // num 表示要移动的个数, a, b, c 分别表示 A 塔，B 塔, C 塔
    public void move(int num, char a, char b, char c) {
        //如果只有一个盘 num = 1
        if (num == 1) {
            System.out.println(a + "->" + c);
        } else {
            //如果有多个盘，可以看成两个 , 最下面的和上面的所有盘(num-1)
            //(1)先移动上面所有的盘到 b,
            move(num - 1, a, c, b);
            //(2)把最下面的这个盘，移动到 c
            System.out.println(a + "->" + c);
            //(3)再把 b 塔的所有盘，移动到 c ,借助 a
            move(num - 1, b, a, c);
        }
    }
}