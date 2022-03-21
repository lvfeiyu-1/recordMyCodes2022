#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//执行用时：32 ms, 在所有 C++ 提交中击败了61.85%的用户
//内存消耗：23.1 MB, 在所有 C++ 提交中击败了93.66%的用户

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len=nums.size();
//        int* newNums=new int[2*len];
//        for(int i=0;i<len;i++){
//            newNums[i]=nums[i];
//        }
//        for(int i=len;i<len+len-1;i++){
//            newNums[i]=nums[i-len];
//        }
        vector<int> ans(len,0);
        stack<int> st;
        for(int i=0;i<len;i++){
            while(!st.empty()&&nums[i]>nums[st.top()]){
                int index=st.top();
                ans[index]=nums[i];
                st.pop();
            }
            st.emplace(i);
        }
        while(!st.empty()){
            int index=st.top();
            int i;
            for(i=0;i<index;i++){
                if(nums[i]>nums[index]){
                    ans[index]=nums[i];
                    break;
                }
            }
            if(i==index)
                ans[index]=-1;
            st.pop();
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
    vector<int> ans=sol.nextGreaterElements(temperatures);
    int len=ans.size();
    for(int i=0;i<len;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}