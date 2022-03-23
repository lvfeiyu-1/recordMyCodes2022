#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//用哈希存前缀和
//执行用时：204 ms, 在所有 C++ 提交中击败了25.15%的用户
//内存消耗：88.1 MB, 在所有 C++ 提交中击败了38.97%的用户
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        //当sum-k==0时算一个，所以mp[0]要等于1
        mp[0]=1;

        int ans=0,sum=0;
        for(int num:nums){
            //只用加一遍求和！
            sum+=num%2;
            mp[sum]++;
            if(sum>=k){
                ans+=mp[sum-k];
            }
        }
        return ans;
    }
};

//时间超限
class Solution2{
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int* preSum=new int[n+1];
        preSum[0]=0;
        for(int i=0;i<n;i++){
            preSum[i+1]=preSum[i]+nums[i]%2;
        }

        int cnt=0;
        for(int end=n;end>=0;end--){
            for(int start=0;start<end;start++){
                if(preSum[end]-preSum[start]==k)
                    cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    vector<int> nums;

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.emplace_back(num);
    }
    int k;
    cin>>k;
    Solution sol;
    int ans=sol.numberOfSubarrays(nums,k);
    cout<<ans<<endl;
    return 0;
}