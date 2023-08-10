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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead ->next = head;
        ListNode *slow= dummyHead;
        ListNode *fast= dummyHead;
        
        for(int dist =0; dist <n+1; dist++)
        {
            fast = fast->next;
        }
        
        while(fast != NULL)
        {
            slow= slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummyHead->next;
    }
};