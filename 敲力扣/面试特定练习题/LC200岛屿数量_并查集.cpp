#include<iostream>
#include<vector>
using namespace std;

//并查集
class Solution {
public:
    int cnt=0;

    int Find(int*parent, int x){
        if(parent[x]==x)
            return x;
        else{
            return parent[x]=Find(parent,parent[x]);
        }
    }

    void Union(int x,int y,int *parent){
        if(Find(parent,x)==Find(parent,y))
            return;
        parent[Find(parent,x)]=Find(parent,y);
//        执行用时：32 ms, 在所有 C++ 提交中击败了60.71%的用户
//        内存消耗：12.6 MB, 在所有 C++ 提交中击败了34.39%的用户
//        cnt--;
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int *parent=new int[m*n];

        //init
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //这个index是之前卡住我的，如何在一维数组中表示一个二维数组
                int index=i*n+j;
                parent[index]=index;
//                if(grid[i][j]=='1')
//                    cnt++;
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    //"i+1<m" 和 “grid[i+1][j]=='1'”位置调换会导致溢出
                    if(i+1<m&&grid[i+1][j]=='1')
                        Union(i*n+j,(i+1)*n+j,parent);
                    if(j+1<n&&grid[i][j+1]=='1')
                        Union(i*n+j,i*n+j+1,parent);
                }
            }
        }

//        执行用时：28 ms, 在所有 C++ 提交中击败了88.85%的用户
//        内存消耗：12.7 MB, 在所有 C++ 提交中击败了33.88%的用户
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int index=i*n+j;
                if(parent[index]==index&&grid[i][j]=='1')
                    cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    vector<vector<char>> grid;
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        vector<char> tmp;
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            tmp.emplace_back(ch);
        }
        grid.emplace_back(tmp);
    }
    Solution sol;
    int ans=sol.numIslands(grid);
    cout<<ans<<endl;
    return 0;
}