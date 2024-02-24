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
    int find(vector<int>&v){
        vector<pair<int, int>>v2;
        for(int i=0; i<v.size(); i++){
            v2.push_back({v[i], i});
        }
        sort(v2.begin(), v2.end());
        int swaps = 0;
        for(int i=0; i<v2.size(); i++){
            if(v2[i].second!=i){
                swap(v2[i], v2[v2[i].second]);
                i--;
                swaps++;
            }
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode* >q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            int s = q.size();
            vector<int>v;
            while(s--){
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans+=find(v);
        }
        return ans;
    }
};