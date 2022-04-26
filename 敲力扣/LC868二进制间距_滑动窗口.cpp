#include<iostream>
#include<vector>
using namespace std;

//自己写出，滑动窗口
//执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗：6.1 MB, 在所有 C++ 提交中击败了5.09%的用户
class Solution {
public:
    int binaryGap(int n) {
        vector<int> binarys;
        while(n!=0){
            binarys.emplace_back(n%2);
            n=n/2;
        }

        int _size=binarys.size();
        int maxLen=0;
        int left=0,right=0;

        while(right<_size){
            if(binarys[left]==0){
                left++;
                continue;
            }

            if(right<=left){
                right++;
            }else if(binarys[right]==0){
                right++;
            }else if(binarys[right]==1){
                maxLen=max(maxLen,right-left);
                left++;
            }
        }

        return maxLen;
    }
};

//方法一：位运算
//思路与算法:
//我们可以使用一个循环从 n 二进制表示的低位开始进行遍历，并找出所有的 1。我们用一个变量 last 记录上一个找到的 1 的位置。
// 如果当前在第 i 位找到了 1，那么就用 i-last 更新答案，再将 last 更新为 i 即可。
//
//在循环的每一步中，我们可以使用位运算 n & 1 获取 n 的最低位，判断其是否为 1。在这之后，我们将 n 右移一位：n = n >> 1，
//这样在第 i 步时，n & 1 得到的就是初始 n 的第 i 个二进制位。
class Solution_answer {
public:
    int binaryGap(int n) {
        //答案的这个方法真是妙啊！
        int last = -1, ans = 0;
        for (int i = 0; n; ++i) {
            if (n & 1) {
                if (last != -1) {
                    ans = max(ans, i - last);
                }
                last = i;
            }
            n >>= 1;
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    Solution sol;
    int ans=sol.binaryGap(n);
    cout<<ans<<endl;
    return 0;
}
