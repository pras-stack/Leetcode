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
        ListNode* prev = nullptr;
    ListNode* current = head;
    
    while (current != nullptr) {
        ListNode* nextNode = current->next; // Store the next node
        current->next = prev; // Reverse the next pointer
        
        // Move the pointers to the next nodes
        prev = current;
        current = nextNode;
    }
    
    return prev; // The new head of the reversed lis
    }
};