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
 struct CompareNode {
 bool operator()(ListNode* A,ListNode* B)
{
    return A->val>B->val;
}
 };
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummynode=new ListNode(0);
        ListNode* tail=dummynode;

        priority_queue<ListNode*,vector<ListNode*>,CompareNode>pq;
        for(auto list:lists)
        {
            if(list!=NULL)
            {
                pq.push(list);
            }
        }
        while(!pq.empty())
        {
            ListNode*smallest=pq.top();
            pq.pop();
            tail->next=smallest;
            tail=tail->next;
            if(smallest->next!=NULL)
            {
                pq.push(smallest->next);
            }

        }
        return dummynode->next;

        
    }
};