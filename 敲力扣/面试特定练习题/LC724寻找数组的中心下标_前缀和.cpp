#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

//自己写的题解
//执行用时：1864 ms, 在所有 C++ 提交中击败了5.03%的用户
//内存消耗：30.3 MB, 在所有 C++ 提交中击败了22.59%的用户
class Solution2 {
public:
    int pivotIndex(vector<int> &nums) {
        int len = nums.size();
        int lsum = 0, rsum = 0;
        for (int i = 0; i < len; i++) {
            lsum = 0;
            rsum = 0;
            for (int j = 0; j < i; j++)
                lsum += nums[j];
            for (int k = i + 1; k < len; k++)
                rsum += nums[k];
            if (lsum == rsum)
                return i;
        }
        return -1;
    }
};

//（官方题解）前缀和
//执行用时：24 ms, 在所有 C++ 提交中击败了39.19%的用户
//内存消耗：30.2 MB, 在所有 C++ 提交中击败了52.02%的用户
class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        //用vector的accumulate求和函数一定要加上头文件 #include<numeric>
        //accumulate求和函数 后面的那个0 是指求和完vector数组后，再额外加上 0
        int sum=accumulate(nums.begin(),nums.end(),0);
        int len=nums.size();

        int lsum=0;
        for(int i=0;i<len;i++){
            if(2*lsum+nums[i]==sum)
                return i;
            lsum+=nums[i];
        }
        return -1;
    }
};

int main() {
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.emplace_back(num);
    }
    Solution sol;
    int ans = sol.pivotIndex(nums);
    cout << ans << endl;
    return 0;
}