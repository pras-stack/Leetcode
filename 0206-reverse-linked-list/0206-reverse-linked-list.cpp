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
    ListNode* reverseList(ListNode* head) 
    {
        stack<ListNode*>st;
        
        ListNode *curr = head;
        
        while(curr!=NULL)
        {
            st.push(curr);
            curr= curr->next;
        }
        
        ListNode *dummyHead = new ListNode(0);
        curr= dummyHead;
        
        while(!st.empty())
        {
            curr->next= st.top();
            curr= curr->next;
            st.pop();
        }
        curr->next = NULL;
        return dummyHead->next;
    }
};