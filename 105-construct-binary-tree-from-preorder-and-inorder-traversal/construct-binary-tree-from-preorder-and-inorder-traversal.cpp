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
    int findNode(vector<int>& in, int s, int e, int t){
        for(int i=s; i<=e; i++){
            if(in[i]==t){
                return i;
            }
        }
        return -1;
    }
    TreeNode* find(int ind, int s, int e, vector<int>& pre, vector<int>& in){
        if(s>e)return NULL;
        TreeNode* root = new TreeNode(pre[ind]);
        int pos = findNode(in, s, e, pre[ind]);
        root->left = find(ind+1, s, pos-1, pre, in);
        root->right = find(ind+(pos-s+1), pos+1, e, pre, in);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        return find(0, 0, n-1, pre, in);
    }
};