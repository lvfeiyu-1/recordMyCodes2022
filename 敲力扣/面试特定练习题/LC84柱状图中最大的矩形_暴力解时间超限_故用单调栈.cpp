#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//执行用时：128 ms, 在所有 C++ 提交中击败了55.54%的用户
//内存消耗：78.2 MB, 在所有 C++ 提交中击败了28.06%的用户

//暴力解法，超出时间限制
class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        int len=heights.size();
        for(int i=0;i<len;i++){
            int left=i,right=i;
            while(left-1>=0&&heights[left-1]>=heights[i])
                left--;
            while(right+1<len&&heights[right+1]>=heights[i])
                right++;
            ans=max(ans,(right-left+1)*heights[i]);
        }
        return ans;
    }
};

//单调栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len=heights.size();
        int *newHeights=new int[len+2];
        newHeights[0]=0;
        for(int i=1;i<=len;i++)
            newHeights[i]=heights[i-1];
        newHeights[len+1]=0;

        int ans=0;
        stack<int> index;
        for(int i=0;i<len+2;i++){
            while(!index.empty()&&newHeights[i]<newHeights[index.top()]){
                int currentindex=index.top();
                index.pop();
                int val=newHeights[currentindex];
                int left=index.top();
                ans=max(ans,val*(i-left-1));
            }
            index.emplace(i);
        }
        return ans;
    }
};

int main(){
    vector<int> heights;
    int n;
    cin>>n;
    while(n--){
        int num;
        cin>>num;
        heights.push_back(num);
    }
    Solution sol;
    int ans=sol.largestRectangleArea(heights);
    cout<<ans<<endl;
    return 0;
}