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
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*>m;
        queue<TreeNode* >q;
        q.push(root);
        TreeNode* startNode = NULL;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                TreeNode* node = q.front();
                q.pop();
                if(node->val==start){
                    startNode = node;
                }
                if(node->left){
                    m[node->left] = node;
                    q.push(node->left);
                }
                if(node->right){
                    m[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        int time=0;
        queue<TreeNode* >q1;
        q1.push(startNode);
        map<TreeNode*, int>vis;
        vis[startNode] = 1;
        bool f=0;
        while(!q1.empty()){
            int s = q1.size();
            f=0;
            time++;
            while(s--){
                TreeNode* node = q1.front();
                q1.pop();
                if(node->left && !vis[node->left]){
                    q1.push(node->left);
                    vis[node->left] = 1;
                    f=1;
                }
                if(node->right && !vis[node->right]){
                    q1.push(node->right);
                    vis[node->right] = 1;
                    f=1;
                }
                if(m[node] && !vis[m[node]]){
                    q1.push(m[node]);
                    vis[m[node]] = 1;
                    f=1;
                }
            }
            // if(f==1)time++;
        }
        return time-1;
    }
};