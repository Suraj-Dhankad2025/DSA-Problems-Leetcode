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
    bool find(TreeNode* root, int k, set<int>&s){
        if(root==NULL)return false;
        if(s.find(k-root->val)!=s.end()){
            return true;
        }
        s.insert(root->val);
        return find(root->left, k, s)||find(root->right, k, s);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)return false;
        set<int>st;
        return find(root, k, st);
    }
};