#include<iostream>
#include<string>
#include<vector>
using namespace std;

//本质上就是排除法，把所有不符合题意的结果全都排除掉
//回溯其实就是横向遍历，纵向递归的组合。
//抱歉这一部分我还没读懂
class Solution {
    vector<string> ans;
    string myS;
    int len;
public:
    void DFS(int begin, int index, string path) {
        // 如果找到了 4 段 IP 地址并且遍历完了字符串，那么就是一种答案
        if (index == 4) {
            if (begin == len)
                ans.emplace_back(path);
            return;
        }
        if (index)
            path += '.';
        //i-begin==3说明分割出来的段有4位了
        //begin + (4 - index) * 3如果小于总长度则说明有多余的位
        //begin + (4 - index) 相当于分割出来的段每一段长度都是 1，是最短的情况
        for (int i = begin; i < len && i - begin < 3 && begin + (4 - index) <= len && begin + (4 - index) * 3 >= len; i++) {
            //段的长度为2 且 最后一位是‘0’
            if (i - begin == 1 && path[path.size() - 1] == '0')
                return;
            else if (i - begin == 2) {
                if (path[path.size() - 2] > '2')
                    return;
                else if (path[path.size() - 2] == '2') {
                    if (path[path.size() - 1] > '5')
                        return;
                    if (path[path.size() - 1] == '5' && myS[i] > '5')
                        return;
                }
            }
            path += myS[i];
            DFS(i + 1, index + 1, path);
        }
        return;
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12)
            return {};
        len = s.size();
        myS = s;
        DFS(0, 0, {});
        return ans;
    }
};

//就嗯循环 反正是常数级，暴力大法好！
//回溯tm的太麻烦
//执行用时：4 ms, 在所有 C++ 提交中击败了41.91%的用户
//内存消耗：6.4 MB, 在所有 C++ 提交中击败了71.48%的用户
class Solution2 {
public:
    bool check(string s)
    {
        //atoi(s)  这样写会报错
        if (atoi(s.c_str()) > 255
        || (atoi(s.c_str()) != 0 && s[0] == '0')
        || (atoi(s.c_str()) == 0 && s.length() > 1))
            return false;
        return true;
    }

    vector<string> restoreIpAddresses(string s)
    {
        if (s.length() > 12 || s.length() < 4)
            return vector<string>();
        int len = s.length();
        vector<string> res;

        for (int i = 1; i <= 3; ++i)
            for (int j = 1; j <= 3; ++j)
                for (int k = 1; k <= 3; ++k)
                    for (int l = 1; l <= 3; l++)
                    {
                        if (i + j + k + l != len)
                            continue;
                        string s1 = s.substr(0, i);
                        string s2 = s.substr(i, j);
                        string s3 = s.substr(i + j, k);
                        string s4 = s.substr(i + j + k, l);
                        if (check(s1) && check(s2) && check(s3) && check(s4))
                            res.push_back(s1 + '.' + s2 + '.' + s3 + '.' + s4);
                    }

        return res;
    }
};

int main() {
    string s;
    cin>>s;
    Solution sol;
    vector<string> ans=sol.restoreIpAddresses(s);
    for(auto& a:ans)
        cout<<a<<" ";
    cout<<endl;
    return 0;
}