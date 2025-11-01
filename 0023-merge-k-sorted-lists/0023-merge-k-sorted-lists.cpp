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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // ✅ Step 1: Define a comparator for the min-heap
        // This lambda ensures the node with the smallest value appears at the top of the heap.
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val; // '>' makes it a min-heap
        };

        // ✅ Step 2: Create a min-heap (priority_queue) using the comparator
        // It will always give us the smallest node among the current list heads.
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        // ✅ Step 3: Push the head of each non-empty list into the heap
        // Initial heap size = number of non-empty linked lists (k)
        for (auto head : lists) {
            if (head) pq.push(head);
        }

        // ✅ Step 4: Create a dummy node to simplify list merging logic
        // This acts as a fixed starting point, avoiding null checks for the first node.
        ListNode dummy(0);    // stack object construction → automatically destroyed later
        ListNode* tail = &dummy;  // tail pointer to track the end of the merged list

        // ✅ Step 5: Extract the smallest node from heap one by one
        // Each time, attach it to the merged list, and push its next node (if any).
        while (!pq.empty()) {
            // Get the node with the smallest value
            ListNode* node = pq.top();
            pq.pop();

            // Attach this node to the merged list
            tail->next = node;
            tail = node; // Move tail forward

            // If the popped node has a next, push it into the heap
            if (node->next) pq.push(node->next);

            // Break old links to keep the merged list clean and avoid cycles
            tail->next = nullptr;
        }

        // ✅ Step 6: Return the head of the merged sorted list
        // dummy.next points to the first real node of our merged list.
        return dummy.next;
    }
};
