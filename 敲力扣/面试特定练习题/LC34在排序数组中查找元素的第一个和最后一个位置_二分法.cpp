#include<iostream>
#include<vector>
using namespace std;

//二分法独立解出，根据报错部分调整了代码，一开始不能马上考虑完情况
//用时击败59.50%，内存消耗击败90.75%
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int len = nums.size();
        if (len == 0)
            return {-1, -1};
        if (len == 1 && nums[0] == target)
            return {0, 0};

        int i = 0, j = len - 1, start = -1, end = -1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[mid] == target) {
                start = mid;
                end = mid;
                //向左排查
                for(int k=mid-1;k>=0;--k){
                    if (nums[k] == target)
                        start = k;
                    else break;
                }
                //向右排查
                for (int k = mid + 1; k < len; k++) {
                    if (nums[k] == target)
                        end = k;
                    else break;
                }
                break;
            }

            if (nums[mid] < target && target <= nums[j]) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return {start, end};
    }
};

int main() {
    vector<int> nums;
    int target;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.emplace_back(num);
    }
    cin >> target;
    Solution sol;
    vector<int> ans = sol.searchRange(nums, target);
    for(int& a:ans)
        cout<<a<<" ";
    cout << endl;
    return 0;
}