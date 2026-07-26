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
    void deleteNode(ListNode* node) {
        if(node==NULL || node->next==NULL)
              return;
        ListNode *curr=node;
        curr=curr->next;
        swap(curr->val,node->val);
        node->next=curr->next;
        
    }
};