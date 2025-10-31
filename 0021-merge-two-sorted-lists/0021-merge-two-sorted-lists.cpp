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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {


        ListNode* ans = new ListNode(0);

        ListNode* newlist = ans;

        if(!l1 && !l2) return nullptr;

        // 3) Standard merge: append exactly ONE node each step (no duplicates)
        while(l1  && l2){
            
            if(l1->val <= l2->val){
                newlist->next = new ListNode(l1->val);
                l1 = l1->next;
            }else{
                newlist->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            newlist = newlist->next;
        }

           while(l1){
            
            newlist->next = new ListNode(l1->val);

            l1 = l1->next;
            newlist = newlist->next;


        }

        while(l2){

            newlist->next = new ListNode(l2->val);

            l2 = l2->next;
            newlist = newlist->next;
        }


     ListNode* head = ans->next;

        return head;
    }
};