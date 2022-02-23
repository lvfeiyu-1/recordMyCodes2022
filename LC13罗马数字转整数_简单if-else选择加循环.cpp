#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        int len=s.length();
        for(int i=0;i<len;i++){
            if(s[i]=='I' && s[i+1]=='V' && i+1!=len){
                ans-=1;
            }else if(s[i]=='I' && s[i+1]=='X' && i+1!=len){
                ans-=1;
            }else if(s[i]=='I'){
                ans+=1;
            }else if(s[i]=='V'){
                ans+=5;
            }else if(s[i]=='X' && s[i+1]=='L' && i+1!=len){
                ans-=10;
            }else if(s[i]=='X' && s[i+1]=='C' && i+1!=len){
                ans-=10;
            }else if(s[i]=='X'){
                ans+=10;
            }else if(s[i]=='L'){
                ans+=50;
            }else if(s[i]=='C' && s[i+1]=='D' && i+1!=len){
                ans-=100;
            }else if(s[i]=='C' && s[i+1]=='M' && i+1!=len){
                ans-=100;
            }else if(s[i]=='C'){
                ans+=100;
            }else if(s[i]=='D'){
                ans+=500;
            }else if(s[i]=='M'){
                ans+=1000;
            }
        }
        return ans;
    }
};

int main(){
    string s;
    cin>>s;
    Solution sol;
    int ans=sol.romanToInt(s);
    cout<<ans<<endl;
    return 0;
}