#include<iostream>
#include<string>
#include<vector>
using namespace std;

//醍醐灌顶，二分法思路是这个鸭！
//将数组一分为二，其中一定有一个是有序的，另一个可能是有序，也能是部分有序。
//此时有序部分用二分法查找。无序部分再一分为二，其中一个一定有序，另一个可能有序，可能无序。就这样循环.
//下面来看答案的题解
class ansSolution {
public:
    //对于有序数组，可以使用二分查找的方法查找元素。
    //但是这道题中，数组本身不是有序的，进行旋转后只保证了数组的局部是有序的，这还能进行二分查找吗？答案是可以的。
    //可以发现的是，我们将数组从中间分开成左右两部分的时候，一定有一部分的数组是有序的。
    //拿示例来看，我们从 6 这个位置分开以后数组变成了 [4, 5, 6] 和 [7, 0, 1, 2] 两个部分，其中左边 [4, 5, 6] 这个部分的数组是有序的，其他也是如此。
    //这启示我们可以在常规二分查找的时候查看当前 mid 为分割位置分割出来的两个部分 [l, mid] 和 [mid + 1, r] 哪个部分是有序的，
    //并根据有序的那个部分确定我们该如何改变二分查找的上下界，因为我们能够根据有序的那部分判断出 target 在不在这个部分：
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) 
                return mid;
            
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

//暴力遍历，简单题重拳出击，但是要注意把时间复杂度优化到O(logn)
//执行用时：4 ms, 在所有 C++ 提交中击败了70.53%的用户
//内存消耗：10.8 MB, 在所有 C++ 提交中击败了67.95%的用户
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
            if(nums[i]==target)
                return i;
        return -1;
    }
};

int main() {
    vector<int> nums;
    int target;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.emplace_back(num);
    }
    cin>>target;
    Solution sol;
    int ans=sol.search(nums,target);
    cout<<endl;
    return 0;
}