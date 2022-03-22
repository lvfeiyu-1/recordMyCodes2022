#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<algorithm>
using namespace std;

//滑动窗口
//执行用时：32 ms, 在所有 C++ 提交中击败了27.51%的用户
//内存消耗：10.5 MB, 在所有 C++ 提交中击败了44.78%的用户
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> occur;
        int n=s.size();

        //枚举左指针
        int right=-1,ans=0;
        for(int i=0;i<n;i++){
            if(i!=0){
                occur.erase(s[i-1]);
            }
            while(right+1<n&&!occur.count(s[right+1])){
                occur.insert(s[right+1]);
                right++;
            }
            ans=max(ans,right-i+1);
        }
        return ans;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        //将字符转换成ACSII值并做好记录
        int* last=new int[128];
        for(int i=0;i<128;i++){
            last[i]=-1;
        }
        int len=s.size();

        //难点是start的变换
        int ans=0;
        int start=0;//窗口开始位置
        for(int i=0;i<len;i++){
            int index=s[i]; //字母转成数字
            start=max(start, last[index]+1);
            ans=max(ans,i-start+1);
            last[index]=i;
        }
    }
};

int main(){
    string s;
    cin>>s;
    Solution sol;
    int ans=sol.lengthOfLongestSubstring(s);
    cout<<ans<<endl;
    return 0;
}