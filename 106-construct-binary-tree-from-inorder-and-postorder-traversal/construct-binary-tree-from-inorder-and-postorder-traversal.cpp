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
    TreeNode* solve(vector<int>& postorder,int &postindex,int inorderstart,int inorderend,unordered_map<int,int>&mp){
        if((postindex<0)||(inorderstart>inorderend))
            return NULL;
        
        int ele=postorder[postindex];
        postindex--;
        int pos=mp[ele];
        TreeNode* root=new TreeNode(ele);
        root->right=solve(postorder,postindex,pos+1,inorderend,mp);
        root->left=solve(postorder,postindex,inorderstart,pos-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>m;
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }
        int size=inorder.size();
        int postindex=size-1,inorderend=size-1,inorderstart=0;
        return solve(postorder,postindex,inorderstart,inorderend, m);
    }
};