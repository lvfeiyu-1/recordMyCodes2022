#include<iostream>
using namespace std;

//执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗：6 MB, 在所有 C++ 提交中击败了87.96%的用户

class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1||n==2)
            return 1;
        int first=1;
        int second=1;
        for(int i=3;i<=n;i++){
            int third=first+second;
            first=second;
            second=third;
        }
        return second;
    }
};

int main(){
    int n;
    cin>>n;
    Solution sol;
    int ans=sol.fib(n);
    cout<<ans<<endl;
    return 0;
}
