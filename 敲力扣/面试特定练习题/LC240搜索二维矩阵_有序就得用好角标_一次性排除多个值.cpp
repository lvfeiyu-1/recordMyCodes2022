#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//执行用时：12 ms, 在所有 C++ 提交中击败了83.83%的用户
//内存消耗：19 MB, 在所有 C++ 提交中击败了88.16%的用户

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int x=0,y=n-1;
        while(x<m&&y>=0){
            if(matrix[x][y]==target)
                return true;
            if(matrix[x][y]>target)
                y--;
            else
                x++;
        }
        return false;
    }
};

int main(){
    vector<vector<int>> matrix;
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        vector<int> nums;
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            nums.push_back(num);
        }
        matrix.push_back(nums);
    }
    int target;
    cin>>target;
    Solution sol;
    bool ans=sol.searchMatrix(matrix,target);
    cout<<ans<<endl;
    return 0;
}