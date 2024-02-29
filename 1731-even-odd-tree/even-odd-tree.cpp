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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level = -1;
        while(!q.empty()){
            int s = q.size();
            level++;
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
            if(level%2==0){
                int prev = -1;
                for(auto i:v){
                    if(i%2==1){
                        if(prev==-1 || prev<i){
                            prev = i;
                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        return false;
                    }
                }
            }
            else{
                int prev = -1;
                for(auto i:v){
                    if(i%2==0){
                        if(prev==-1 || prev>i){
                            prev = i;
                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};