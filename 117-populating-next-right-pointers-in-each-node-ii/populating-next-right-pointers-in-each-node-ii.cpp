/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
        return nullptr;
    Node* currLevelFirstNode = root;
    while(currLevelFirstNode) {
        Node* currentNode = currLevelFirstNode;
        currLevelFirstNode = nullptr;
        Node* lastConnectedNode = nullptr;
        while(currentNode) {
            for(auto& child : {currentNode->left, currentNode->right}) {
                if(!child)
                    continue;
                if(!currLevelFirstNode)
                    currLevelFirstNode = child;
                if(lastConnectedNode)
                    lastConnectedNode->next = child;
                lastConnectedNode = child;
            }
            currentNode = currentNode->next;
        }          
    }
    return root;
    }
};