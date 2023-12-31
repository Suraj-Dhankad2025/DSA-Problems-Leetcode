/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*>vis;
    void dfs(Node* node, Node* clone){
        for(auto it:node->neighbors){
            if(!vis[it->val]){
                Node* newNode = new Node(it->val);
                vis[it->val] = newNode;
                clone->neighbors.push_back(newNode);
                dfs(it, newNode);
            }
            else{
                clone->neighbors.push_back(vis[it->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        Node* clone = new Node(node->val);
        vis.resize(200, NULL);
        vis[node->val] = clone;
        dfs(node, clone);
        return clone;
    }
};