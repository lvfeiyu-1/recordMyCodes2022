#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

//执行用时：8 ms, 在所有 C++ 提交中击败了97.71%的用户
//内存消耗：13.2 MB, 在所有 C++ 提交中击败了71.10%的用户

class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int>& m,pair<int,int>& n){
            return m.second>n.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto& num:nums){
            m[num]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> q;
        for(auto& key:m){
            if(q.size()==k){
                if(q.top().second<key.second){
                    q.pop();
                    q.emplace(key);
                }
            }else{
                q.emplace(key);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.emplace_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};

int main(){
    vector<int> nums;
    int len;
    cin>>len;
    for(int i=0;i<len;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    int k;
    cin>>k;
    Solution sol;
    vector<int> ans=sol.topKFrequent(nums,k);

    for(auto n:ans)
        cout<<n<<" ";
    cout<<endl;

    return 0;
}