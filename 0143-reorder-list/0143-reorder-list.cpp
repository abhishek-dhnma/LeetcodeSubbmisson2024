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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return; // 0,1,2 nodes: already ordered

        // 1) Find middle (slow ends at end of first half)
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // For odd length: first half has one extra node

        // 2) Split and reverse second half
        ListNode* l1 = head;
        ListNode* l2 = slow->next;
        slow->next = nullptr;  // split

        // Reverse l2 in-place
        ListNode* prev = nullptr;
        ListNode* cur  = l2;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        l2 = prev; // head of reversed second half

        // 3) Merge alternately: l1 -> l2 -> l1 -> l2 ...
        while (l1 && l2) {
            ListNode* l1n = l1->next;
            ListNode* l2n = l2->next;

            l1->next = l2;
            l2->next = l1n;

            l1 = l1n;
            l2 = l2n;
        }
        // No need to terminate explicitly; links already correct
    }
};
