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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(head1==NULL)return head2;
        if(head2==NULL)return head1;
        ListNode* prev = new ListNode(-1);
        ListNode*temp = prev;
        while(head1!=NULL && head2!=NULL){
            if(head1->val<=head2->val){
                prev->next = head1;
                head1 = head1->next;
            }
            else{
                prev->next = head2;
                head2 = head2->next;
            }
            prev = prev->next;
        }
        if(head1==NULL){
            prev->next = head2;
        }
        else{
            prev->next = head1;
        }
        return temp->next;
    }
};