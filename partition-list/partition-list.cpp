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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return NULL;
        ListNode * sE = new ListNode(-1);
        ListNode * gE = new ListNode(-1);
        ListNode* sH = sE, *gH = gE;
        while(head!=NULL){
            if(head->val<x){
                sE->next=head;
                sE = sE->next;
            }
            else{
                gE->next = head;
                gE = gE->next;
            }
            head = head->next;
        }
        gE->next = NULL;
        sE->next = gH->next;
        return sH->next;
    }
};