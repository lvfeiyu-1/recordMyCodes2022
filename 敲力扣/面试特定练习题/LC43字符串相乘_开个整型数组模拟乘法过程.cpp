#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//开个整型数组模拟乘法过程
//执行用时：4 ms, 在所有 C++ 提交中击败了87.10%的用户
//内存消耗：6.5 MB, 在所有 C++ 提交中击败了83.53%的用户
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
            return "0";
        int len1 = num1.length();
        int len2 = num2.length();

        int* ans=new int[len1 + len2];
        for(int i=0;i<len1+len2;i++)
            ans[i]=0;

        int i, j;
        for (i = len1 - 1; i >= 0; --i) {
            for (j = len2 - 1; j >= 0; --j) {
            	//不懂这个过程，一定要动笔在纸上模拟一下
                int num = (num1[i]-48) * (num2[j] - 48) + ans[i+j+1];
                //主要是这个 “＋” 脑子无法直接理解，最好自己模拟一下
                ans[i+j] += num / 10;
                ans[i+j+1] = num % 10;
            }
        }

        string sans;
        for(i=0;i<len1+len2;i++){
            if(ans[i]==0&&i==0)
                continue;
            sans+=ans[i]+48;
        }
        return sans;
    }

};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    //string ans(1+1+1,'0');
    Solution sol;
    string ans = sol.multiply(s1, s2);
    cout << ans << endl;
    return 0;
}
