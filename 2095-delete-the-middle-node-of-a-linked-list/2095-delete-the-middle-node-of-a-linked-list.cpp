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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp;
         ListNode* prev=NULL;
         if (head == NULL || head->next == NULL) {
            return NULL;
        }
        temp=head;
        int k=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            k++;
        }
        temp=head;
        for(int i=0;i<k/2;i++)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        return head;
       
        
    }
};