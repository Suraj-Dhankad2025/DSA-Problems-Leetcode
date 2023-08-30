/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*>q;
        if(root==NULL){
            return {};
        }
        vector<vector<int>>ans;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int>v;
            for(int i=0; i<s; i++){
                Node* temp = q.front();
                q.pop();
                v.push_back(temp->val);
                for(auto i:temp->children){
                    q.push(i);
                }
            }
            ans.push_back(v);     
        }
        return ans;
    }
};