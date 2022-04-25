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

int main(){
    int n;
    cin>>n;
    Solution sol;
    int ans=sol.binaryGap(n);
    cout<<ans<<endl;
    return 0;
}