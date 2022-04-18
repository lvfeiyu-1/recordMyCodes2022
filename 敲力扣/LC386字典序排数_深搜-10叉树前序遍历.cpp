#include<iostream>
#include<vector>
using namespace std;

//深搜：10叉树先序遍历
//执行用时：12 ms, 在所有 C++ 提交中击败了41.83%的用户
//内存消耗：10.7 MB, 在所有 C++ 提交中击败了78.09%的用户
class Solution {
public:
    vector<int> res;
    vector<int> lexicalOrder(int n) {
        res.reserve(n);
        for(int i=1;i<=9;i++){
            dfs(i,n);
        }
        return res;
    }
    void dfs(int cur,int n){
        if(cur>n)
            return;
        res.emplace_back(cur);
        for(int i=0;i<=9;++i){
            dfs(cur*10+i,n);
        }
    }
};

int main(){
    int n;
    cin>>n;
    Solution sol;
    vector<int> res=sol.lexicalOrder(n);
    for(auto& a:res)
        cout<<a<<" ";
    cout<<endl;
    return 0;
}
