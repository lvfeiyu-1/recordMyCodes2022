#include<iostream>
#include<vector>
using namespace std;

///执行用时：4 ms, 在所有 C++ 提交中击败了97.39%的用户
///内存消耗：17.8 MB, 在所有 C++ 提交中击败了80.52%的用户

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //int len=nums.size();
        int slow=1,fast=1;
        while(fast<nums.size()){
            if(nums[fast]!=nums[fast-1]){
                nums[slow]=nums[fast];
                fast++;
                slow++;
            }else{
                fast++;
            }
        }
        return slow;
    }
};

int main() {
    vector<int> nums;
    int tmp;
    while(cin>>tmp){
        nums.emplace_back(tmp);
    }
    Solution sol;
    int ans=sol.removeDuplicates(nums);
    cout<<ans<<endl;
    return 0;
}