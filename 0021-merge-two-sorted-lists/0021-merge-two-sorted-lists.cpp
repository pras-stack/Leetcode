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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* dummy = new ListNode(0); // Create a dummy node to simplify code
    ListNode* current = dummy; // Pointer to the current node in the merged list
    
    // Compare elements from both lists and add the smaller one to the merged list
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    
    // If there are remaining nodes in one of the lists, add them to the merged list
    if (l1 != nullptr) {
        current->next = l1;
    } else {
        current->next = l2;
    }
    
    return dummy->next; 
    }
};