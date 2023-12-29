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
        if(!head || !head->next){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        while(curr!=nullptr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(-1);
        ListNode* list1 = rev(l1);
        ListNode* list2 = rev(l2);
        int carry = 0;
        ListNode* temp1 = temp;
        int num = 0;
        while(list1!=NULL || list2!=NULL){
            if(list1!=nullptr && list2!=nullptr){
                num = list1->val+list2->val + carry;
            }
            else if(list1==nullptr && list2!=nullptr){
                num = list2->val + carry;
            }
            else {
                num = list1->val+ carry;
            }

            ListNode* newl = new ListNode(num%10);
            temp1->next = newl;
            temp1 = temp1->next;
            carry = num/10;
            if(list1)
                list1 = list1->next;
            if(list2)
                list2 = list2->next;

        }
        if(carry!=0){
            ListNode* temp2 = new ListNode(carry);
            temp1->next = temp2;
            temp1 = temp2;
        }
        temp = temp->next;
        temp = rev(temp);
        return temp;
    }
};