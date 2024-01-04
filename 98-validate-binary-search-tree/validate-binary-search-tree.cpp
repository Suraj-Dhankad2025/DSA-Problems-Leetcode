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
    bool checkBST(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root==NULL)return true;
        if(min!=NULL && root->val<=min->val){
            return false;
        }
        if(max!=NULL && root->val>=max->val){
            return false;
        }
        bool left = checkBST(root->left, min, root);
        bool right = checkBST(root->right, root, max);
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        if (root->left == NULL && root->right == NULL){
            return true;        
        }
        return checkBST(root, NULL, NULL); 
    }
};