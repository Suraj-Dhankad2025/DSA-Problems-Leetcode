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
    ListNode* rev(ListNode* head){
        ListNode* cur=head, *prev=NULL, *nxt = NULL;
        while(cur!=NULL){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return; 
        }
        ListNode* fast=head, *slow=head, *pre=NULL;
        while(fast!=NULL && fast->next!=NULL){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        ListNode* temp = head;
        ListNode* temp1 = rev(slow);
        ListNode* newHead = new ListNode(0);
        ListNode* newTail = newHead;
        bool f=0;
        while(temp!=NULL){
            if(f==0){
                f=1;
                newTail->next = temp;
                temp=temp->next;
            }
            else{
                f=0;
                newTail->next = temp1;
                temp1=temp1->next;
            }
            newTail = newTail->next;
        }
        if(temp1!=NULL){
            newTail->next = temp1;
        }
        head = newHead->next;
    }
};