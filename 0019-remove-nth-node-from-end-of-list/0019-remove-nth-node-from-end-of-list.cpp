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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL||head->next==NULL)
        return NULL;
    
        ListNode* temp=new ListNode();
        ListNode* prev=new ListNode();
        temp=head;
        int k=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            k++;

        }
        if(k==n)
        {
            return head->next;
        }
        temp=head;
        for(int i=1;i<=k-n;i++)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        return head;

        
    }
};