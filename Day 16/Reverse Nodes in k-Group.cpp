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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        int counting=1;
        while(temp!=NULL)
        {
            temp=temp->next;
            counting++;
            
        }
        
        
        if(head==NULL )
        {
            return NULL;
            
        }
        ListNode* prv=NULL;
        ListNode* cur=head;
        ListNode* next=NULL;
        int count=0;
        while(cur!=NULL && count<k )
        {
         
            next=cur->next;
            cur->next=prv;
            prv=cur;
            cur=next;
            count++;
            
        }
        if(cur!=NULL && counting-k>k  )
        {
            head->next=reverseKGroup(cur,k);
        }
        else
        {
            head->next=cur;
        }
        
        return prv;
    }
};