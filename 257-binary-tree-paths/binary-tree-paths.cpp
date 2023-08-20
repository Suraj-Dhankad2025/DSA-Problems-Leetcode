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
    vector<string>ans;
    void find(TreeNode* root, string s){
        if(root->left==NULL && root->right==NULL){
            s+=to_string(root->val);
            ans.push_back(s);
            return ;
        }
        s = s + to_string(root->val);
        if(root->left)find(root->left, s+"->");
        if(root->right)find(root->right, s+"->");
      
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
        find(root, s);
        return ans;
    }
};