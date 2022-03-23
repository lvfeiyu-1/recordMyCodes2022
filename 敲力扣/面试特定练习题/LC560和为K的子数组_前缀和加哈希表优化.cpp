#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//普通前缀和
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len=nums.size();
        int* preSum=new int[len+1];
        preSum[0]=0;
        //这样子用数组存每一个位的前缀和我是没有想到
        for(int i=0;i<len;i++)
            preSum[i+1]=preSum[i]+nums[i];
        int cnt=0;
        for(int left=0;left<len;left++){
            for(int right=left;right<len;right++){
                //区间和[left,right],注意下标偏移
                if(preSum[right+1]==preSum[left]+k)
                    cnt++;
            }
        }
        return cnt;
    }
};

//方法二：前缀和 + 哈希表优化
//这个实在是完全没有想到，但是我还是拿这个提交力扣了，因为枚举和普通前缀和都过不了，时间超限
//迟点看到注释要记得回来把它弄明白哦
//执行用时：60 ms, 在所有 C++ 提交中击败了86.21%的用户
//内存消耗：35.2 MB, 在所有 C++ 提交中击败了64.53%的用户
class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> preSumFreq;
        preSumFreq[0]=1;

        int preSum=0;
        int cnt=0;
        for(int num:nums){
            preSum+=num;
            if(preSumFreq.find(preSum-k)!=preSumFreq.end()){
                cnt+=preSumFreq[preSum-k];
            }
            preSumFreq[preSum]++;
        }
        return cnt;
    }
};

    //枚举   85 / 89 个通过测试用例, 时间超限了
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        int len=nums.size();
//        int sum=0,left=0,right=0;
//
//        int cnt=0;
//        while(left<len){
//            while(right<len){
//                sum+=nums[right];
//                right++;
//                if(sum==k)
//                    cnt++;
//            }
//            left++;
//            right=left;
//            sum=0;
//        }
//        return cnt;
//    }
//};

int main() {
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.emplace_back(num);
    }
    int k;
    cin>>k;
    Solution sol;
    int ans = sol.subarraySum(nums,k);
    cout << ans << endl;
    return 0;
}