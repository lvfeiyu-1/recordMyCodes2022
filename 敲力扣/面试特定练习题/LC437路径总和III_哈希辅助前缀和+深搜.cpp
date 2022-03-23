#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(){
        val=0;
        left= nullptr;
        right= nullptr;
    }

    TreeNode(int x){
        val=x;
        left= nullptr;
        right= nullptr;
    }

    TreeNode(int x, TreeNode *left, TreeNode *right){
        val=x;
        this->left=left;
        this->right=right;
    }
};

class Tree{
    TreeNode* root;
    int pos;
public:
    void Create(int* nums,int len){
        pos=0;
        root=CreateTree(nums,len);
    }
    TreeNode* CreateTree(int *nums,int len){
        TreeNode* node;
        if(pos>=len)
            return nullptr;
        int num=nums[pos++];
        if(num==0){
            node= nullptr;
        }else{
            node=new TreeNode(num);
            node->left= CreateTree(nums,len);
            node->right= CreateTree(nums,len);
        }
        return node;
    }
    void PreOrder(TreeNode* node){
        if(node){
            cout<<node->val<<" ";
            PreOrder(node->left);
            PreOrder(node->right);
        }
    }
    TreeNode *getRoot() const {
        return root;
    }
};


//哈希表辅助前缀和+深度搜索
//执行用时：16 ms, 在所有 C++ 提交中击败了76.29%的用户
//内存消耗：19.6 MB, 在所有 C++ 提交中击败了15.38%的用户

class Solution {
public:
    unordered_map<int,int> mp;
    int target,ans;
    int pathSum(TreeNode *root, int targetSum) {
        target=targetSum;
        mp[0]=1;
        ans=0;
        dfs(root,0);
        return ans;
    }

    void dfs(TreeNode* root, int sum){
        if(!root)
            return ;
        sum+=root->val;
        ans+=mp[sum-target];
        if(mp.find(sum)!=mp.end())
            mp[sum]++;
        else
            mp[sum]=1;
        dfs(root->left,sum);
        dfs(root->right,sum);
        mp[sum]--;
    }

};

int main() {
    int num;
    cin>>num;
    int* nums=new int[num];
    for(int i=0;i<num;i++){
        cin>>nums[i];
    }
    Tree tree;
    tree.Create(nums,num);
    tree.PreOrder(tree.getRoot());

    int target;
    cin>>target;
    Solution sol;
    int ans=sol.pathSum(tree.getRoot(),target);
    cout<<ans<<" "<<endl;
    return 0;
}

/* 差点栽在自己的输入数据上了
19
10 5 3 3 0 0 -2 0 0 2 0 1 0 0 -3 0 11 0 0
10 5 3 3 -2 2 1 -3 11
8
3*/
