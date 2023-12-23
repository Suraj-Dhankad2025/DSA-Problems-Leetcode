/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int find(TreeNode*root, unordered_map<TreeNode*, int>&dp){
        if(!root)return 0;

        if(dp.find(root)!=dp.end())return dp[root];
        int take = 0,notTake=0;
        take+=root->val;
        if(root->left){
            take += find(root->left->left,dp) + find(root->left->right,dp);
        }
        if(root->right){
            take += find(root->right->left,dp) + find(root->right->right,dp);
        }
        notTake = find(root->left,dp) + find(root->right,dp);
        return dp[root] = max(take, notTake);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int>dp;
        return find(root,dp);
    }
};