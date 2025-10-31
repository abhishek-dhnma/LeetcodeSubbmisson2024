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

        while(l1 && l2){
            if(l1->val <= l2->val){
                newlist->next = l1;
                l1 = l1->next;
            }else{
                newlist->next = l2;
                l2 = l2->next;
            }
            newlist = newlist->next;
        }

        newlist->next = (l1 ? l1 : l2);

        return ans->next;

        
    }
};