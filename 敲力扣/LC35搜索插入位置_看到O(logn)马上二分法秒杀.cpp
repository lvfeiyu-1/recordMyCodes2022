//执行用时：4 ms, 在所有 C++ 提交中击败了76.36%的用户
//内存消耗：9.3 MB, 在所有 C++ 提交中击败了96.72%的用户

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int len = nums.size();
        int i = 0, j = len - 1;
        int mid = (i + j) / 2;
        while (i <= j) {
            if (nums[mid] > target)
                j = mid - 1;
            else if (nums[mid] < target)
                i = mid + 1;
            else
                return mid;
            mid = (i + j) / 2;
        }
        return i;
    }
};
