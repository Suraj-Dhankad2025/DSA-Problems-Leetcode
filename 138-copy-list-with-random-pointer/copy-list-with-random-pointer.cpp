/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       if(head==NULL)return head;
       Node*temp = head;
       while(temp!=NULL){
           Node*newNode = new Node(temp->val);
           newNode->next = temp->next;
           temp->next = newNode; 
           temp = newNode->next;
       }
       temp = head;
       while(temp!=NULL){
           temp->next->random=(temp->random!=NULL)?temp->random->next:NULL;
           temp = temp->next->next;
       }
       Node* oldList = head;
       Node* newList = head->next;
       Node* newHead = head->next;
        while(oldList!=NULL){
           oldList->next = oldList->next->next;
           newList->next = (newList->next!=NULL)?newList->next->next:NULL;
           oldList = oldList->next;
           newList = newList->next;
        }
       return newHead;
       }
};