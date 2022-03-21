#include<iostream>
#include<vector>
using namespace std;

//并查集
//执行用时：20 ms, 在所有 C++ 提交中击败了71.36%的用户
//内存消耗：13.4 MB, 在所有 C++ 提交中击败了53.75%的用户

class Solution {
public:
    int Find(int x,int* parents){
        if(parents[x]==x)
            return x;
        else{
            while(parents[x]!=x){
                x=parents[x];
            }
        }
        return x;
    }

    void Union(int *parents,int x,int y){
        parents[Find(x,parents)]=Find(y,parents);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int len=isConnected.size();
        int *parents=new int[len];
        for(int i=0;i<len;i++)
            parents[i]=i;

        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(isConnected[i][j]==1)
                    Union(parents,i,j);
            }
        }

        int circle=0;
        for(int i=0;i<len;i++){
            if(parents[i]==i)
                circle++;
        }
        return circle;
    }
};

int main(){
    vector<vector<int>> isConnected;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> tmp;
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            tmp.emplace_back(num);
        }
        isConnected.emplace_back(tmp);
    }
    Solution sol;
    int ans=sol.findCircleNum(isConnected);
    cout<<ans<<endl;
    return 0;
}