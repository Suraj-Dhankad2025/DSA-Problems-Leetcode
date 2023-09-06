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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            n++;
        }
        vector<ListNode*>ans;
        int rem = n%k;
        int listLen = n/k;
        temp = head;
        int c=0;
        while(temp!=NULL){
            ListNode* tail = new ListNode(0);
            ListNode* newHead = tail;
            c = listLen;
            while(c--){
                tail->next = new ListNode(temp->val);
                tail = tail->next;
                temp = temp->next;
            }
            if(rem>0){
                tail->next = new ListNode(temp->val);
                temp = temp->next;
                tail = tail->next;
                rem--;
            }
            ans.push_back(newHead->next);
        }
        if(listLen==0 && ans.size()!=k){
           while(ans.size()!=k){
               ans.push_back(NULL);
           }
        }
        return ans;
    }
};