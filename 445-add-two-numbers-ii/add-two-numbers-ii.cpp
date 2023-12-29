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
        ListNode* prev = NULL, *cur = head, *nxt = NULL;
        while(cur!=NULL){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = rev(l1);
        ListNode* h2 = rev(l2);
        ListNode* temp1 = h1;
        ListNode* temp2 = h2;
        int carry = 0;
        ListNode* newHead = new ListNode(-1);
        ListNode* tempHead = newHead;
        while(temp1!=NULL && temp2!=NULL){
            int num = temp1->val + temp2->val + carry;
            ListNode* node = new ListNode(num%10);
            carry = num/10;
            tempHead->next = node;
            tempHead = tempHead->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1!=NULL){
            ListNode* node = new ListNode((temp1->val+carry)%10);
            carry = (temp1->val+carry)/10;
            tempHead->next = node;
            tempHead = tempHead->next;
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            ListNode* node = new ListNode((temp2->val+carry)%10);
            carry = (temp2->val+carry)/10;
            tempHead->next = node;
            tempHead = tempHead->next;
            temp2 = temp2->next;
        }
        if(carry!=0){
            ListNode* node = new ListNode(carry);
            tempHead->next = node;
            tempHead = tempHead->next;
        }
        return rev(newHead->next);
    }
};