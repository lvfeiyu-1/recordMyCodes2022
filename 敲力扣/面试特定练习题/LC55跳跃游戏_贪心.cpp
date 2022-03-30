#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

//贪心算法
//执行用时：60 ms, 在所有 C++ 提交中击败了29.80%的用户
//内存消耗：47.1 MB, 在所有 C++ 提交中击败了87.00%的用户
//遍历一次数组，维护一个最远距离
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n=nums.size();
        if(n==1)
            return true;
        int index=1;
        int maxDis=nums[0];
        while(index<n){
            if(index<=maxDis){
                maxDis=max(index+nums[index],maxDis);
                index++;
                if(maxDis>=n-1)
                    return true;
            }else{
                break;
            }
        }
        return false;
    }
};

int main() {
    vector<int> ob;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        ob.emplace_back(num);
    }
    Solution sol;
    bool ans = sol.canJump(ob);
    cout << ans << endl;
    return 0;
}