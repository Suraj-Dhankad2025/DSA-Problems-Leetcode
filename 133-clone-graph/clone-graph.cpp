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
    void dfs(Node* copy,Node* orig,map<int,Node*>&mp){
        mp[orig->val] =copy;
        for(auto currnode:orig->neighbors){
            if(mp[currnode->val]==NULL){
                Node* naya=new Node(currnode->val);
                (copy->neighbors).push_back(naya);
                dfs(naya,currnode,mp);
            }
            else{
                (copy->neighbors).push_back(mp[currnode->val]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr)return node;
        map<int,Node*>mp;
        Node* copy=new Node(node->val);
        mp[node->val]=copy;
        for(auto currnode:node->neighbors){
            if(mp[currnode->val]==NULL){
                Node* naya=new Node(currnode->val);
                (copy->neighbors).push_back(naya);
                dfs(naya,currnode,mp);
            }
            else{
                (copy->neighbors).push_back(mp[currnode->val]);
            }
        }
        return copy;
    }
};