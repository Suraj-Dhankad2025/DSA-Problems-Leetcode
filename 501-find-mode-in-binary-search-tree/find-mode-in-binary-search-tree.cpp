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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int>m;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            for(int i=0; i<s; i++){
                TreeNode* node = q.front();
                q.pop();
                m[node->val]++;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        int c=0;
        vector<int>ans;
        for(auto it:m){
            c = max(c,it.second);
        }
        for(auto it:m){
            if(it.second==c){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};