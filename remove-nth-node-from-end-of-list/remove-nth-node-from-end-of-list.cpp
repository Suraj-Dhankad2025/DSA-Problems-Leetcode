/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)return head;
        if(head->next ==NULL && n==1)return NULL; 
        if(n==0)return head;
        int N = 1;
        ListNode *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
            N++;
        }
        if(n==N){
            return head->next;
        }
        int s = N-n+1;
        
        int count=1;
        temp = head;
        ListNode *prev=NULL;
        while(count<s){
            prev = temp;
            temp = temp->next;
            count++;
        }
        prev->next = temp->next;
        temp->next = NULL;
        return head;
    }
    
};