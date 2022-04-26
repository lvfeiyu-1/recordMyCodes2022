#include<iostream>
#include<vector>
using namespace std;

//答案的数学方法
//执行用时：4 ms, 在所有 C++ 提交中击败了96.45%的用户
//内存消耗：9 MB, 在所有 C++ 提交中击败了81.21%的用户
class Solution {
public:
    int projectionArea(vector<vector<int>> &grid) {
        int n = grid.size();
        int xyArea = 0, yzArea = 0, zxArea = 0;
        for (int i = 0; i < n; i++) {
            int yzHeight = 0, zxHeight = 0;
            for (int j = 0; j < n; j++) {
                xyArea += grid[i][j] > 0 ? 1 : 0;
                yzHeight = max(yzHeight, grid[j][i]);
                zxHeight = max(zxHeight, grid[i][j]);
            }
            yzArea += yzHeight;
            zxArea += zxHeight;
        }
        return xyArea + yzArea + zxArea;
    }
};

int main(){
    vector<vector<int>> grid;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> tmp;
        for(int j=0;j<n;++j){
            int num;
            cin>>num;
            tmp.emplace_back(num);
        }
        grid.emplace_back(tmp);
    }
    Solution sol;
    int ans=sol.projectionArea(grid);
    cout<<ans<<endl;
    return 0;
}