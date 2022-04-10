#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//我自己写的拓扑排序，42/44，最后时间超限了
class Solution2 {
public:
    int **adj;
    int *Indegree;
    int *visited;
    queue<int> q;

    void fun(int num,int index){
        for(int i=index;i<num;i++){
            if(!Indegree[i]){
                if(!visited[i]){
                    q.emplace(i);
                    visited[i]=1;
                }
                for(int j=0;j<num;j++){
                    if(adj[i][j]){
                        adj[i][j]=0;
                        Indegree[j]--;
                        if(Indegree[j]==0){
                            fun(num,j);
                        }
                    }
                }
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int m=prerequisites.size();
        //int n=prerequisites[0].size(); //一定是2

        adj=new int*[numCourses+2];
        for(int i=0;i<numCourses+2;i++)
            adj[i]=new int[numCourses+2];

        for(int i=0;i<numCourses+2;i++)
            for(int j=0;j<numCourses+2;j++)
                adj[i][j]=0;

        Indegree=new int[numCourses+2];
        for(int i=0;i<numCourses+2;++i)
            Indegree[i]=0;

        visited=new int[numCourses+2];
        for(int i=0;i<numCourses+2;++i)
            visited[i]=0;

        for(int i=0;i<m;i++){
            adj[prerequisites[i][1]][prerequisites[i][0]]=1;
            Indegree[prerequisites[i][0]]++;
        }

        fun(numCourses,0);

        vector<int> ans;
        while(!q.empty()){
            ans.emplace_back(q.front());
            q.pop();
        }
        if(ans.size()!=numCourses)
            return {};
        return ans;
    }
};


//拓扑排序，广度优先遍历
//执行用时：88 ms, 在所有 C++ 提交中击败了5.24%的用户
//内存消耗：79.8 MB, 在所有 C++ 提交中击败了5.01%的用户
class Solution {
public:
    int **adj;
    int *Indegree;
    int *visited;
    queue<int> q;
    vector<int> ans;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int m=prerequisites.size();
        //int n=prerequisites[0].size();  //一定是2
        adj=new int*[numCourses+2];
        for(int i=0;i<numCourses+2;i++)
            adj[i]=new int[numCourses+2];

        for(int i=0;i<numCourses+2;i++)
            for(int j=0;j<numCourses+2;j++)
                adj[i][j]=0;

            Indegree=new int[numCourses+2];
            for(int i=0;i<numCourses+2;++i)
                Indegree[i]=0;

            visited=new int[numCourses+2];
            for(int i=0;i<numCourses+2;++i)
                visited[i]=0;

            for(int i=0;i<m;i++){
                adj[prerequisites[i][1]][prerequisites[i][0]]=1;
                Indegree[prerequisites[i][0]]++;
            }

            for(int i=0;i<numCourses;i++)
                if(Indegree[i]==0)
                    q.emplace(i);

            while(!q.empty()){
                 int tmp=q.front();
                 q.pop();
                 ans.emplace_back(tmp);
                 for(int i=0;i<numCourses;++i){
                     if(adj[tmp][i]){
                         adj[tmp][i]=0;
                         Indegree[i]--;
                         if(Indegree[i]==0)
                             q.emplace(i);
                     }
                 }
            }

            if(ans.size()!=numCourses)
                return {};
            return ans;
    }
};

// 用vector完全可以代替一维或多维数组
class Solution1 {
public:
    //int **adj;
    //int *Indegree;
    //int *visited;
    queue<int> q;
    vector<int> ans;

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        int m = prerequisites.size();
        //int n=prerequisites[0].size(); //一定是2

        //adj = new int *[numCourses + 2];
        //for (int i = 0; i < numCourses + 2; i++)
        //adj[i] = new int[numCourses + 2];

        //事实证明，用vector完全可以代替一维或多维数组，而且理论上会更快
        vector<vector<int>> adj(numCourses + 2, vector<int>(numCourses + 2, 0));

        vector<int> Indegree(numCourses+2,0);

        vector<int> visited(numCourses+2,0);
        //for (int i = 0; i < numCourses + 2; i++)
        //for (int j = 0; j < numCourses + 2; j++)
        //adj[i][j] = 0;

        //Indegree = new int[numCourses + 2];
        //for (int i = 0; i < numCourses + 2; ++i)
        //Indegree[i] = 0;

        //visited = new int[numCourses + 2];
        //for (int i = 0; i < numCourses + 2; ++i)
        //visited[i] = 0;

        for (int i = 0; i < m; i++) {
            adj[prerequisites[i][1]][prerequisites[i][0]] = 1;
            Indegree[prerequisites[i][0]]++;
        }

        for (int i = 0; i < numCourses; i++)
            if (Indegree[i] == 0)
                q.emplace(i);

        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            ans.emplace_back(tmp);
            for (int i = 0; i < numCourses; ++i) {
                if (adj[tmp][i]) {
                    adj[tmp][i] = 0;
                    Indegree[i]--;
                    if (Indegree[i] == 0)
                        q.emplace(i);
                }
            }
        }

        if (ans.size() != numCourses)
            return {};
        return ans;
    }
};

int main(){
    int numCourses;
    vector<vector<int>> prerequisites;
    cin>>numCourses;
    for(int i=0;i<numCourses;i++){
        vector<int> tmp;
        for(int j=0;j<2;j++){
            int num;
            cin>>num;
            tmp.emplace_back(num);
        }
        prerequisites.emplace_back(tmp);
    }
    cin>>numCourses;
    Solution sol;
    vector<int> ans=sol.findOrder(numCourses,prerequisites);
    for(int & a:ans){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
