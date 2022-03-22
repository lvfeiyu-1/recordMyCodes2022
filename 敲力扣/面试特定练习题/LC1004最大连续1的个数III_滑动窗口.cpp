#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

//滑动窗口，用cnt计数处理左指针变换问题
//执行用时：52 ms, 在所有 C++ 提交中击败了50.65%的用户
//内存消耗：54 MB, 在所有 C++ 提交中击败了90.50%的用户
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len=nums.size();
        int left=0,right=0;
        int cnt=0;

        int ans=0;
        while(right<len){
            if(nums[right]==0){
                cnt++;
            }
            right++;
            while(cnt>k){
                if(nums[left]==0)
                    cnt--;
                left++;
            }
            ans=max(ans,right-left);
        }
        return ans;
    }
};

//官方答案
class Solution2 {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, lsum = 0, rsum = 0;
        int ans = 0;
        
        //这里用求和代替了上面的cnt，也很巧妙
        for (int right = 0; right < n; ++right) {
            rsum += 1 - nums[right];
            while (lsum < rsum - k) {
                lsum += 1 - nums[left];
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main(){
    vector<int> nums;
    int k,n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.emplace_back(num);
    }
    cin>>k;
    Solution sol;
    int ans=sol.longestOnes(nums,k);
    cout<<ans<<endl;
    return 0;
}