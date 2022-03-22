#include<iostream>
#include<vector>
using namespace std;

//并查集
//执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗：8.5 MB, 在所有 C++ 提交中击败了69.72%的用户
class Solution {
public:
    int Find(int x,int* parent){
        if(parent[x]==x)
            return x;
        else
            return parent[x] = Find(parent[x],parent);
    }

    void Union(int x,int y,int* parents){
        parents[parents[x]]=parents[y];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int m=edges.size();

        //init
        int *parents=new int[2*m];
        for(int i=0;i<m;i++){
            for(int j=0;j<2;j++){
                int index=i*2+j;
                parents[index]=index;
            }
        }


        vector<int> ans;
        for(int i=0;i<m;i++){
            int x=edges[i][0];
            int y=edges[i][1];
            if(Find(x,parents)==Find(y,parents))
                ans=edges[i];
            else
                Union(x,y,parents);
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> edges;
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        vector<int> tmp;
        for(int j=0;j<2;j++){
            int num;
            cin>>num;
            tmp.emplace_back(num);
        }
        edges.emplace_back(tmp);
    }
    Solution sol;
    vector<int> ans=sol.findRedundantConnection(edges);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}