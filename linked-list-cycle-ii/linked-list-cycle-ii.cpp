/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        bool f=0;
        // if(head->next==NULL)return 0;
        ListNode*slow = head, *fast = head;
        ListNode*temp=head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                f=1;
                break;
            }
        }
        if(f==0){
            return 0;
        }
        while(slow!=temp){
            slow = slow->next;
            temp = temp->next;
        }
        return temp;
    }
};