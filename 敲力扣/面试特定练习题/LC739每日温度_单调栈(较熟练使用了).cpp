#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//执行用时：176 ms, 在所有 C++ 提交中击败了10.16%的用户
//内存消耗：86.8 MB, 在所有 C++ 提交中击败了54.05%的用户

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len=temperatures.size();
        vector<int> ans(len,0);
        stack<int> st;
        for(int i=0;i<len;i++){
            while(!st.empty()&&temperatures[i]>temperatures[st.top()]){
                int index=st.top();
                int tmp=i-index;
                ans[index]=tmp;
                st.pop();
            }
            st.emplace(i);
        }
        return ans;
    }
};

int main(){
    vector<int> temperatures;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        temperatures.emplace_back(num);
    }
    Solution sol;
    vector<int> ans=sol.dailyTemperatures(temperatures);
    int len=ans.size();
    for(int i=0;i<len;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}