#include<iostream>
#include<vector>
using namespace std;

//差分数组
//执行用时：12 ms, 在所有 C++ 提交中击败了62.10%的用户
//内存消耗：10.2 MB, 在所有 C++ 提交中击败了46.87%的用户
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //因为你本来出租车上一个人都没有，即原数列是0，所以差分数列一开始全是0
        vector<int> d(1002,0);
        for(vector<int>& e:trips){
            d[e[1]]+=e[0];
            d[e[2]]-=e[0];
        }

        for(int i=0;i<1001;i++){
            if(i)
                d[i]+=d[i-1];
            if(d[i]>capacity)
                return false;
        }
        return true;
    }
};

int main(){
    vector<vector<int>> trips;
    int capacity;

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> tmp;
        for(int i=0;i<3;i++){
            int num;
            cin>>num;
            tmp.emplace_back(num);
        }
        trips.emplace_back(tmp);
    }

    cin>>capacity;
    Solution sol;
    bool ans=sol.carPooling(trips,capacity);
    cout<<ans<<endl;
    return 0;
}