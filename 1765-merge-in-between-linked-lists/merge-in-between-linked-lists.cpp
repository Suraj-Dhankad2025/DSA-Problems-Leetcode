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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;
        ListNode* prev = NULL;
        int c=0;
        while(temp!=NULL){
            if(c==a){
                break;
            }
            prev = temp;
            temp = temp->next;
            c++;
        }
        temp = list1;
        c=0;
        while(temp!=NULL){
            if(c==b){
                break;
            }
            temp = temp->next;
            c++;
        }
        ListNode* temp1 = list2;
        while(temp1->next!=NULL){
            temp1 = temp1->next;
        }
        prev->next = list2;
        temp1->next = temp->next;
        return list1;
    }
};