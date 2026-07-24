/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr=head;
        while(curr!=NULL)
        {
        Node* copy=new Node(curr->val);
        copy->next=curr->next;
        curr->next=copy;
        curr=curr->next->next;
        }
        curr=head;
        while(curr)
        {
            if(curr->random!=NULL)
            {
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;

        }
        curr=head;
        Node* dummyNode=new Node(0);
        Node* add=dummyNode;
        while(curr!=NULL)
        {
            Node* copy=curr->next;
            add->next=copy;
            curr->next=copy->next;
            add=copy;
            curr=curr->next;
        }
        return dummyNode->next;
        
    }
};