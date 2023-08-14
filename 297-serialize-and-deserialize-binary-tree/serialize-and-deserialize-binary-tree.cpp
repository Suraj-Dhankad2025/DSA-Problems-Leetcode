/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)return "null,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* make(queue<string>&q){
        if(q.front()=="null"){
            q.pop();
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(q.front()));
        q.pop();
        node->left = make(q);
        node->right = make(q);
        return node; 
    }
    TreeNode* deserialize(string data) {
        queue<string>q;
        string s;
        for(int i=0; i<data.size(); i++){
            if(data[i]==','){
                q.push(s);
                s="";
                continue;
            }   
            s+=data[i];
        }
        if(s.size()!=0)q.push(s);
        return make(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));