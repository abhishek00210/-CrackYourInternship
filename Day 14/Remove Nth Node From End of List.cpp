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
         if (head == NULL)
        return NULL;

    int length = 0;
    ListNode* temp = head;
    while (temp != NULL) 
    {
        length = length + 1;
        temp = temp->next;
    }
    
    length = length - n;
    if (length == 0) 
    {
        temp = head->next;
        head->next = NULL;
        delete(head);
        return temp;
    }
    
    ListNode* curr = head;
    ListNode* prev = NULL;
    
    while (length > 0) 
    {
        prev = curr;
        curr = curr->next;
        length = length - 1;
    }
    
    prev->next = curr->next;
    curr->next = NULL;
    delete(curr);
    return head;
}
};