#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//回溯
//执行用时：188 ms, 在所有 C++ 提交中击败了15.78%的用户
//内存消耗：7.3 MB, 在所有 C++ 提交中击败了28.22%的用户
class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int res=0;
    int sum=0;
    int n,m;

    int getMaximumGold(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                sum=0;
                if(grid[i][j])
                    dfs(grid,i,j);
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& grid,int x,int y){
        int g=grid[x][y];
        sum+=g;
        grid[x][y]=0;
        for(int k=0;k<4;++k){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny])
                dfs(grid,nx,ny);
        }
        res=max(res,sum);
        grid[x][y]=g;
        sum-=g;
    }
};

int main(){
    vector<vector<int>> grid;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        vector<int> tmp;
        for(int j=0;j<m;++j){
            int num;
            cin>>num;
            tmp.emplace_back(num);
        }
        grid.emplace_back(tmp);
    }
    Solution sol;
    int ans=sol.getMaximumGold(grid);
    cout<<ans<<endl;
    return 0;
}