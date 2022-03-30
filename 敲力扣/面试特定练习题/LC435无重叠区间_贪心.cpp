#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//贪心，先对一维数组进行排序，然后用类似于双指针的算法，好像贪心都要排序是嘛
//执行用时：460 ms, 在所有 C++ 提交中击败了9.30%的用户
//内存消耗：87.6 MB, 在所有 C++ 提交中击败了91.48%的用户
class Solution {
public:
    static bool cmp(vector<int>& n1,vector<int>& n2) {
        return n1[1] < n2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        int n = intervals.size();
        
        //力扣官方题解的   匿名内部排序
        //sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
            //return u[1] < v[1];
        //});

        sort(intervals.begin(), intervals.end(), cmp);

        int pre=intervals[0][1];
        int cnt=1;
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=pre){
                cnt++;
                pre=intervals[i][1];
            }
        }
        return n-cnt;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> intervals;
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        int n1, n2;
        cin >> n1 >> n2;
        tmp.emplace_back(n1);
        tmp.emplace_back(n2);
        intervals.emplace_back(tmp);
    }
    Solution sol;
    int ans = sol.eraseOverlapIntervals(intervals);
    cout << ans << endl;
    return 0;
}