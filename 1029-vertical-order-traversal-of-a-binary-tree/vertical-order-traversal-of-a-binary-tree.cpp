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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int , multiset<int>>>mp;
        queue<pair<TreeNode*, pair<int, int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            pair<TreeNode*, pair<int,int>> p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int lvl = p.second.second;
            int hd = p.second.first;
            mp[hd][lvl].insert(node->val);
            if(node->left){
                q.push({node->left, {hd-1, lvl+1}});
            }
            if(node->right){
                q.push({node->right, {hd+1, lvl+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto i:mp){
            vector<int>v;
            for(auto j:i.second){
                for(auto k: j.second){
                    v.push_back(k);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};