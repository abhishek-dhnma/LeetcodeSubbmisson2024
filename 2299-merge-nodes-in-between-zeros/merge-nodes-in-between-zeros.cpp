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
    ListNode* mergeNodes(ListNode* head) {

        ListNode * temp = head->next;
        int sum = 0;
        ListNode * pre = temp;

        while(temp != NULL ){
            if(temp->val == 0){
                temp->val = sum;
                pre->next = temp; 
                pre = temp;
                sum = 0;
            }else{
                sum = temp->val + sum;
            }
            temp = temp->next;
        }
        return head->next->next;
    }
};