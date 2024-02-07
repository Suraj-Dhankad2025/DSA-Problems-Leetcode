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
    Node* clone(unordered_map<Node*, Node*>&m, Node* node){
        Node* newNode = new Node(node->val);
        m[node] = newNode;
        for(auto i:node->neighbors){
            if(m.find(i)==m.end()){
                newNode->neighbors.push_back(clone(m, i));
            }
            else{
                 newNode->neighbors.push_back(m[i]);
            }
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        unordered_map<Node*, Node*>m;
        return clone(m, node);
    }
};