//执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗：8.5 MB, 在所有 C++ 提交中击败了50.74%的用户

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        digits[len - 1] += 1;
        for (int i = len - 1; i >= 0; i--) {
            if (i == 0 && digits[i] == 10) {
                digits.push_back(1);
                for (int j = len; j > 0; j--) {
                    if (j == 1) {
                        digits[j] = 0;
                    } else
                        digits[j] = digits[j - 1];
                }
                digits[i] = 1;
                break;
            }
            if (digits[i] == 10) {
                digits[i] = 0;
                digits[i - 1] += 1;
            } else {
                break;
            }
        }
        return digits;
    }
};
