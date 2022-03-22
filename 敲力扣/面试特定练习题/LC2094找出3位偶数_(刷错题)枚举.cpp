#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

//枚举
//执行用时：624 ms, 在所有 C++ 提交中击败了30.91%的用户
//内存消耗：10.3 MB, 在所有 C++ 提交中击败了49.70%的用户
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> set;
        int n=digits.size();

        //遍历三个数位的下标
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i==k||i==j||j==k)
                        continue;
                    int num=digits[i]*100+digits[j]*10+digits[k];
                    if(num>=100&&num%2==0)
                        set.insert(num);
                }
            }
        }

        vector<int> ans;
        for(auto& num:set){
            ans.emplace_back(num);
        }

        sort(ans.begin(),ans.end(),less<int>());
        return ans;
    }
};

int main(){
    vector<int> digits;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        digits.emplace_back(num);
    }
    Solution sol;
    vector<int> ans=sol.findEvenNumbers(digits);
    for(auto& i:ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}