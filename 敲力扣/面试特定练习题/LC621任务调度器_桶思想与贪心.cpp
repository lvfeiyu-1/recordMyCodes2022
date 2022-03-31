#include<iostream>
#include<vector>
#include<unordered_map>
//#include<algorithm>
using namespace std;

//桶思想，贪心
//执行用时：56 ms, 在所有 C++ 提交中击败了62.34%的用户
//内存消耗：33.7 MB, 在所有 C++ 提交中击败了23.77%的用户
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(char& ch:tasks)
            mp[ch]++;
        int len=tasks.size();
        int maxNum=0;
        for(int i=0;i<len;i++)
            if(mp[tasks[i]]>maxNum)
                maxNum=mp[tasks[i]];

        int ans=(maxNum-1)*(n+1);
        for(int i=0;i<26;i++){
            if(mp[(char)('A'+i)]==maxNum)
                ans++;
        }
        return max(ans,(int)tasks.size());
    }
};

int main(){
    vector<char> tasks;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char ch;
        cin>>ch;
        tasks.emplace_back(ch);
    }
    cin>>n;
    Solution sol;
    int ans=sol.leastInterval(tasks,n);
    cout<<ans<<endl;
    return 0;
}