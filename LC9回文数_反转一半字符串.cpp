#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0&&x!=0))
            return false;
        int reverseNum=0;
        while(x>reverseNum){
            reverseNum=reverseNum*10+x%10;
            x/=10;
        }
        if(reverseNum==x || reverseNum/10==x)
            return true;
        return false;
    }
};

int main(){
    int x;
    cin>>x;
    Solution sol;
    bool ans=sol.isPalindrome(x);
    cout<<"bool: "<<ans;
    return 0;
}