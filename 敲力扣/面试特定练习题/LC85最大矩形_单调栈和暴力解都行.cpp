#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//暴力求解法
//执行用时：44 ms, 在所有 C++ 提交中击败了54.29%的用户
//内存消耗：12.4 MB, 在所有 C++ 提交中击败了89.18%的用户
class Solution2 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int** arr=new int*[m];
        for(int i=0;i<m;i++)
            arr[i]=new int[n];
        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    if(j==0)
                        arr[i][j]=1;
                    else{
                        arr[i][j]=arr[i][j-1]+1;
                    }
                }else{
                    arr[i][j]=0;
                }

                int minWidth=arr[i][j];
                for(int up=i;up>=0;up--){
                    int height=i-up+1;
                    minWidth=min(minWidth,arr[up][j]);
                    ans=max(ans,minWidth*height);
                }
            }
        }
        return ans;
    }
};

//单调栈
//执行用时：36 ms, 在所有 C++ 提交中击败了83.07%的用户
//内存消耗：13.7 MB, 在所有 C++ 提交中击败了46.37%的用户
class Solution {
public:
    int fun(int* heights,int n){
        int* tmp=new int[n+2];
        tmp[0]=0;
        for(int i=1;i<=n;i++)
            tmp[i]=heights[i-1];
        tmp[n+1]=0;
        int ans=0;

        stack<int> st;
        for(int i=0;i<n+2;i++){
            while(!st.empty()&&tmp[i]<tmp[st.top()]){
                int val=tmp[st.top()];
                st.pop();
                int left=st.top();
                ans=max(ans,val*(i-left-1));
            }
            st.emplace(i);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int* heights=new int[n];
        for(int i=0;i<n;i++)
            heights[i]=0;
        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')
                    heights[j]++;
                else
                    heights[j]=0;
            }
            ans=max(ans,fun(heights,n));
        }
        return ans;
    }
};

int main(){
    vector<vector<char>> matrix;
    int m,n;
    char ch;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        vector<char> tmp;
        for(int j=0;j<n;j++){
            cin>>ch;
            tmp.emplace_back(ch);
        }
        matrix.emplace_back(tmp);
    }
    Solution sol;
    int ans=sol.maximalRectangle(matrix);
    cout<<ans<<endl;
    return 0;
}