#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//bfs+队列
//执行用时：16 ms, 在所有 C++ 提交中击败了79.75%的用户
//内存消耗：11.5 MB, 在所有 C++ 提交中击败了90.72%的用户
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Tree{
    Node* root;
    int pos;
public:
    void Create(vector<int>& nums){
        pos=0;
        root=createTree(nums);
    }
    //N叉树怎么建呢？
    //一种思路是，先确定是几叉树，然后递归建树，在建树的时候输入值
    Node* createTree(vector<int>& nums){
        if(nums.empty())
            return nullptr;
        Node* node;
        int num=nums[pos++];
        if(num==0)
            node=nullptr;
        else{
            node=new Node(num);
            //
//            node->left= createTree(nums);
//            node->right= createTree(nums);
        }
        return node;
    }

    Node *getRoot() const {
        return root;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        vector<int> tmp;
        queue<Node*> que;
        //Node* wall=new Node(0);
        que.emplace(root);
        //que.emplace(wall);
        while(!que.empty()){
            int n=que.size();
            for(int i=0;i<n;i++){
                Node* node=que.front();
                que.pop();
                tmp.emplace_back(node->val);
                for(auto& child:node->children){
                    que.emplace(child);
                }
            }
            ans.emplace_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;++i){
        int num;
        cin>>num;
        nums.emplace_back(num);
    }
    Tree tree;
    tree.Create(nums);
    Solution sol;
    vector<vector<int>> ans=sol.levelOrder(tree.getRoot());
    for(auto& vecs:ans){
        for(auto& vec:vecs){
            cout<<vec<<" ";
        }
        cout<<endl;
    }
    return 0;
}