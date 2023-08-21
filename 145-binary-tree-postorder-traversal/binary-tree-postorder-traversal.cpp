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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)return {};
        stack<TreeNode*>s;
        s.push(root);
        TreeNode*prev=NULL;
        vector<int>ans;
        while(!s.empty()){
            TreeNode* curr=s.top();
            if((curr->left==NULL && curr->right==NULL) || (prev!=NULL && (prev==curr->left || prev==curr->right))){
                s.pop();
                ans.push_back(curr->val);
                prev = curr;
            }
            else{
                if(curr->right){
                    s.push(curr->right);
                }
                if(curr->left){
                    s.push(curr->left);
                }
            }
        }
        return ans;
    }
};