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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 
    TreeNode* make(vector<int>&a, int l, int r){
        if(l>r)return NULL;
        int mid = (l+r)/2;
        TreeNode* node = new TreeNode(a[mid]);
        node->left = make(a,l,mid-1);
        node->right = make(a,mid+1,r);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>a;
        ListNode* temp=head;
        while(temp!=NULL){
            a.push_back(temp->val);
            temp = temp->next;
        }
        return make(a,0,a.size()-1);
    }
};