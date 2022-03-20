#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//执行用时：12 ms, 在所有 C++ 提交中击败了91.66%的用户
//内存消耗：19 MB, 在所有 C++ 提交中击败了89.55%的用户

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
            if(map[nums[i]]>nums.size()/2)
                return nums[i];
        }
        return -1;
    }
};

int main(){
    vector<int> nums;
    int n;
    cin>>n;
    while(n--){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    Solution sol;
    int ans=sol.majorityElement(nums);
    cout<<ans<<endl;
    return 0;
}