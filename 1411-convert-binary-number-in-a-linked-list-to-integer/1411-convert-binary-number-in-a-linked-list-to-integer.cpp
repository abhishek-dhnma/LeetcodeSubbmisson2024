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
    int getDecimalValue(ListNode* head) {

        int sum = 0;
        int i = 0;

        ListNode *curr = head;
        ListNode *prev = NULL;

        while (curr != NULL) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev =  curr;
            curr = next;
        }

        while (prev != NULL) {

            sum += (prev->val * pow(2,i));

            prev = prev->next;
            i++;
        }

        return sum;
    }
};