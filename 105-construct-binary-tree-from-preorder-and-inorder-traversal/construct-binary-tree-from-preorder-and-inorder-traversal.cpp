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
    TreeNode* find(vector<int>&pre, int preS, int preE, vector<int>&in, int inS, int inE, map<int, int>&m){
        if(preS>preE||inS>inE){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[preS]);
        int inRoot = m[pre[preS]];
        int numLeft = inRoot - inS;
        root->left = find(pre, preS+1, preS + numLeft, in, inS, inRoot-1, m);
        root->right = find(pre, preS + numLeft+1, preE, in, inRoot+1, inE, m);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>m;
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }
        TreeNode* root = find(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, m);
        return root;
    }
};