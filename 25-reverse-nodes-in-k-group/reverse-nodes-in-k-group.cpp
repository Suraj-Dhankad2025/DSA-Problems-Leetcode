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
    ListNode* find(ListNode* head, int k, int l){
        if(l<k){
            return head;
        }
        if(head==NULL){
            return NULL;
        }
        int c=0;
        ListNode* prev=NULL,*cur=head,*nxt=NULL;
        while(cur!=NULL && c<k){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            c++;
            if(k==0){
                break;
            }
        }
        head->next = find(cur, k, l-k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp = head;
        int c=0;
        while(temp!=NULL){
            temp = temp->next;
            c++;
        }
        if(c<k){
            return head;
        }
        return find(head, k, c);  
    }
};