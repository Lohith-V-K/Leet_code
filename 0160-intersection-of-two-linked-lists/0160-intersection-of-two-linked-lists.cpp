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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* nodea=headA;
        ListNode* nodeb=headB;
        while(nodea!=nodeb)
        {
            if(nodea==NULL)
            {
                nodea=headB;
            }
            else
            nodea=nodea->next;
            if(nodeb==NULL)
            {
                nodeb=headA;
            }
            else
            nodeb=nodeb->next;
            
            
        }
        return nodea;
        
    }
};