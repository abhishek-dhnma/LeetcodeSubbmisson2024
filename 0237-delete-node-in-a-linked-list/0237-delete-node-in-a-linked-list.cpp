/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *curr = node;

        while(curr){
            curr->val = curr->next->val;
            if(curr->next->next == NULL){
                delete curr->next;
                curr->next = NULL;
            }
            curr = curr->next;

        }
        
    }
};