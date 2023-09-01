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
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int>ans;
        // TreeNode* cur = root;
        // while(cur!=NULL){
        //     if(cur->left==NULL){
        //         ans.push_back(cur->val);
        //         cur = cur->right;
        //     }
        
        //     else{
        //         TreeNode* prev = cur->left;
        //         while(prev->right!=NULL && prev->right!=cur){
        //             prev = prev->right;
        //         }
        //         if(prev->right==NULL){
        //             prev->right = cur;
        //             cur = cur->left;
        //         }
        //         else{
        //             prev->right = NULL;
        //             ans.push_back(cur->val);
        //             cur = cur->right;
        //         }
        //     }
        // }
        // return ans;
        vector<int>ans;
        stack<pair<TreeNode*, int>>s;
        s.push({root, 0});
        while(!s.empty()){
            pair<TreeNode*, int>p = s.top();
            if(p.first==NULL){
                s.pop();
                continue;
            }
            s.top().second++;
            if(p.second==1){
                s.push({p.first->left, 0});
            }   
            else if(p.second==2){
                ans.push_back(p.first->val);
                s.push({p.first->right, 0});
            }
            else if(p.second==3){
                s.pop();
            }
        }
        return ans;
    }
};