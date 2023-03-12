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
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty() || lists.size() == 0)
        {
            return NULL;
        }

        // This comparator will be used to build MIN HEAP.
        // We use a LAMBDA to define the comparator.
        auto comp = [&](ListNode *a, ListNode *b) {
            return a->val > b->val;
        };

        priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> pq(comp);

       
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i])
            {
                pq.push(lists[i]);
            }
        }

        ListNode dummyHead(0);
        ListNode *tail = &dummyHead;

        while (!pq.empty())
        {
           
            auto temp = pq.top();
            pq.pop();

            tail->next = temp;
            tail = tail->next;

            if (temp->next)
            {
                pq.push(temp->next);
            }
        }

        tail->next = NULL;

        return dummyHead.next;
    }
};