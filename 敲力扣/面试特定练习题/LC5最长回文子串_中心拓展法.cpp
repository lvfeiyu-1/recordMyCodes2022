#include<iostream>
#include<string>
using namespace std;

//还有动态规划来空间换时间，但是就先不看dp了

//中心拓展法
//执行用时：88 ms, 在所有 C++ 提交中击败了61.11%的用户
//内存消耗：226 MB, 在所有 C++ 提交中击败了36.54%的用户
class Solution {
public:
    int isHuiwen(string s,int left,int right){
        while(left>=0&&right<s.length()){
            if(s[left]==s[right])
                left--,right++;
            else
                break;
        }
        //返回长度要想想
        return right-left-1;
    }

    string longestPalindrome(string s) {
        int len=s.length();
        if(len<2)
            return s;

        int begin=0;
        int maxLen=1;
        for(int i=0;i<len;i++){
            int oddNum=isHuiwen(s,i,i); //奇数中心
            int evenNum= isHuiwen(s,i,i+1); //偶数中心

            int maxNum=max(oddNum,evenNum);
            if(maxNum>maxLen){
                //起始位置要想想
                begin=i-(maxNum-1)/2;
                maxLen=maxNum;
            }
        }
        return s.substr(begin,maxLen);
    }
};

//自己写的，根据答案修改了一下，又时间超限了
//47 / 180 个通过测试用例
class Solution1 {
public:
    bool isHuiwen(string s,int left,int right){
        while(left<right){
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int len=s.length();
        if(len<2)
            return s;

        int maxLen=1;
        int begin=0;
        for(int i=0;i<len-1;i++){
            for(int j=i+1;j<len;j++){
                if(j-i+1>maxLen&&isHuiwen(s,i,j)){
                    begin=i;
                    maxLen=j-i+1;
                }
            }
        }
        return s.substr(begin,maxLen);
    }
};

//自己写的，又时间超限了
//118 / 180 个通过测试用例
class Solution2 {
public:
    bool isHuiwen(string s){
        int len=s.length();
        int left=0,right=len-1;
        while(left<=right){
            if(s[left]==s[right])
                left++,right--;
            else
                return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int len=s.length();
        if(len==1)
            return s;

        int maxLen=0;
        string maxs="";
        for(int i=0;i<len;i++){
            for(int j=maxLen+1;j<=len-i;j++){
                bool flg=isHuiwen(s.substr(i,j));
                if(flg){
                    int tLen=s.substr(i,j).length();
                    if(maxLen<tLen){
                        maxLen=tLen;
                        maxs=s.substr(i,j);
                    }
                }
            }
        }
        return maxs;
    }
};

int main(){
    string s;
    cin>>s;
    Solution sol;
    string ans=sol.longestPalindrome(s);
    cout<<ans<<endl;
    return 0;
}