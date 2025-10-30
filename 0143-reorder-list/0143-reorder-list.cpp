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

        if(!head || !head->next) return;

        
        // find mid of linked list

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* l1 = head;
        ListNode* l2 = slow->next;
        slow->next = nullptr;

        // reverse l2

        ListNode* curr = l2;
        ListNode* prev = nullptr;

        while(curr){
            // next pointer
            ListNode* nxt = curr->next;
            
            // reverse link
            curr->next = prev;

            // shift
            prev = curr;
            curr = nxt;
        }

        l2 = prev; // head of reversed second half


        // merge l1 and l2

        while(l1 && l2){

            ListNode* l1n = l1->next;
            ListNode* l2n = l2->next;

            l1->next = l2;
            l2->next = l1n;


            l1 = l1n;
            l2 = l2n;
        }

    }
};