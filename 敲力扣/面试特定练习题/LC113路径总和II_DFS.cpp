#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Tree{
    TreeNode* root;
    int pos;
    int len;
public:
    void makeTree(int* nums,int n){
        len=n;
        pos=0;
        root=Create(nums);
    }
    TreeNode* Create(int* nums){
        if(pos>=len)
            return NULL;
        TreeNode* node;
        int num=nums[pos++];
        if(num==0){
            node=NULL;
        }else{
            node=new TreeNode(num);
            node->left= Create(nums);
            node->right= Create(nums);
        }
        return node;
    }

    TreeNode *getRoot() const {
        return root;
    }
};

//DFS
//执行用时：4 ms, 在所有 C++ 提交中击败了92.57%的用户
//内存消耗：19.4 MB, 在所有 C++ 提交中击败了63.89%的用户
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        vector<int> tmp;

        tmp.emplace_back(root->val);
        dfs(ans,tmp,root,root->val,targetSum);
        return ans;
    }
    void dfs( vector<vector<int>>& ans,vector<int>& tmp,TreeNode* root,int Sum,int targetSum){
        if(Sum==targetSum&&!root->left&&!root->right)
            ans.emplace_back(tmp);
        else{
            if(root->left){
                tmp.emplace_back(root->left->val);
                dfs(ans,tmp,root->left,Sum+root->left->val,targetSum);
                tmp.pop_back();
            }
            if(root->right){
                tmp.emplace_back(root->right->val);
                dfs(ans,tmp,root->right,Sum+root->right->val,targetSum);
                tmp.pop_back();
            }
        }
    }
};

int main() {
    int n;
    cin>>n;
    int* nums=new int[n+1];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Tree tree;
    tree.makeTree(nums,n);
    Solution sol;
    int targetSum=0;
    cin>>targetSum;
    vector<vector<int>> ans=sol.pathSum(tree.getRoot(),targetSum);
    for(auto& n1:ans){
        for(auto& n2:n1){
            cout<<n2<<" ";
        }
        cout<<endl;
    }
    return 0;
}