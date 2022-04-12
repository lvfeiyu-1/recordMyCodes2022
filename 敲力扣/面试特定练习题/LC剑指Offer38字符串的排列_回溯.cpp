#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//回溯，回溯就是递归，回溯就是可以联系树形结构思考
//执行用时：32 ms, 在所有 C++ 提交中击败了58.97%的用户
//内存消耗：19.8 MB, 在所有 C++ 提交中击败了76.09%的用户
class Solution {
public:
    vector<string> res;
    vector<bool> visited;

    void backtracking(int idx,int n,string& tmp,string s){
        if(idx==n){
            res.emplace_back(tmp);
            return;
        }
        
        //横向循环，不懂什么意思请看笔记“大二下学期”
        for(int i=0;i<n;i++){
            //剪枝操作
            if(visited[i]||(i>0&&s[i]==s[i-1]&&!visited[i-1]))
                continue;
            //收集部分
            visited[i]=true;
            tmp.push_back(s[i]);
            //纵向递归
            backtracking(idx+1,n,tmp,s);
            //回溯部分
            //要弹出收集的东西，恢复原状
            tmp.pop_back();
            visited[i]=false;
        }
    }

    vector<string> permutation(string s) {
        int n=s.size();
        //vector的resize挺好用的
        visited.resize(n, false);
        
        //一定要排序，只有排序才能剪枝
        sort(s.begin(),s.end());
        string tmp;
        //开始深搜
        backtracking(0,n,tmp,s);
        return res;
    }
};

int main(){
    string s;
    cin>>s;
    Solution sol;
    vector<string> res=sol.permutation(s);
    for(auto& a:res)
        cout<<a<<" ";
    cout<<endl;
    return 0;
}