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
        stack<ListNode*>st;  //coz we are pushing node's addresses here
        
        ListNode *curr = head;
        
        while(curr!=NULL)
        {
            st.push(curr);
            curr= curr->next; //move to next node
        }
        
        // Create a dummyHead to build the reversed list
    ListNode* dummyHead = new ListNode(0);  // Create a dummy node to serve as the head of the reversed list
    curr = dummyHead;  // Initialize a current pointer for the reversed list
    
    // Pop nodes from the stack to build the reversed list
    while (!st.empty()) {
        curr->next = st.top();  // Connect the current node to the top node of the stack
        curr = curr->next;  // Move the current pointer to the newly added node
        st.pop();  // Pop the top node from the stack
    }
    
    curr->next = NULL;  // Set the next of the last node to NULL
    return dummyHead->next;  // Return the head of the reversed list
    }
};