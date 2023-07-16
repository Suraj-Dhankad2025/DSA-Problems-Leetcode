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
    ListNode* reverse(ListNode* head){
        ListNode* cur=head,*prev=NULL,*nxt=NULL;
        while(cur!=NULL){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return ;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*remove=NULL;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            remove = slow;
            slow = slow->next;
        }
        remove->next = NULL;

        ListNode* head1 = head;
        ListNode* head2 = reverse(slow);
        ListNode* prev = new ListNode(-1);
        ListNode* newHead = prev;
        bool f=1;
        while(head1!=NULL && head2!=NULL){
            if(f==0){
                prev->next = head2;
                head2 = head2->next;
                f=1;
            }
            else{
                prev->next = head1;
                head1 = head1->next;
                f=0;
            }
            prev = prev->next;
        }
        if(head1==NULL){
            prev->next = head2;
        }
        else{
            prev->next = head1;
        }
        head = newHead->next;
    }
};