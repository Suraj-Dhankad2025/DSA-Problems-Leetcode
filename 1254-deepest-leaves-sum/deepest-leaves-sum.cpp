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
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        queue<TreeNode*>q;
        queue<TreeNode*>q1;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            q1 = q;
            for(int i=0; i<s;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        while(!q1.empty()){
            TreeNode* node = q1.front();
            q1.pop();
            sum+=node->val;
        }
        return sum;
    }
};