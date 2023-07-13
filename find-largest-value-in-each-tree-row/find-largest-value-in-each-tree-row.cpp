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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)return {};
        queue<pair<TreeNode*, int>>q;
        vector<int>ans;
        q.push({root,0});
        int a = INT_MIN;
        int prevLevel = 0;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second; 
            q.pop();

            if(prevLevel == level){
                a = max(a, node->val);
            }
            else{
                ans.push_back(a);
                prevLevel = level;
                a = node->val;
            }

            if(node->left){
                q.push({node->left,level+1});
            }
            if(node->right){
                q.push({node->right, level+1});
            }
        }
        ans.push_back(a);
        return ans;
    }
};