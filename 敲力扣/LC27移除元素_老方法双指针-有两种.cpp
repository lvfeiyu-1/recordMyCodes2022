#include<iostream>
#include<vector>
using namespace std;

//执行用时：4 ms, 在所有 C++ 提交中击败了41.02%的用户
//内存消耗：8.4 MB, 在所有 C++ 提交中击败了93.58%的用户

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len=nums.size();
        int pos=0;
        for(int move=0;move<len;move++){
            if(nums[move]!=val){
                nums[pos++]=nums[move];
            }
        }
        return pos;
    }
};

/*  另一个版本的双指针（双指针优化：从左到右找到与val相同的位置就将其覆盖）
 * 
 * class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                right--;
            } else {
                left++;
            }
        }
        return left;
    }
};
 * */

int main() {
    Solution sol;
    int val;
    vector<int> nums;
    //输入存在问题
    while(cin>>val){
        nums.emplace_back(val);
    }
    cin>>val;
    int ans=sol.removeElement(nums,val);
    cout<<ans<<endl;
    return 0;
}