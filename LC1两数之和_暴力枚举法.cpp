#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    ans.emplace_back(i);
                    ans.emplace_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums;
    int target,len,num;
    cin>>len;
    for(int i=0;i<len;i++){
        cin>>num;
        nums.emplace_back(num);
    }
    cin>>target;
//    for(int i=0;i<nums.size();i++)
//        cout<<nums[i]<<" ";
    Solution sol;
    vector<int> ans=sol.twoSum(nums,target);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
