/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==p||root==q){
            return root;
        }
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode* r=lowestCommonAncestor(root->right,p,q);
        if(l!=NULL&&r!=NULL){
            return root;
        }
        if((root==p&&(l!=NULL||r!=NULL))||(root==q&&(l!=NULL||r!=NULL))){
            return root;
        }
        if(l==NULL){
            return r;
        }
        else return l;
    }
};