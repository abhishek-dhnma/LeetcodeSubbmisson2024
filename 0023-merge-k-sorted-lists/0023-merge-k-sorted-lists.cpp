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

        auto lambda = [](ListNode* l1, ListNode* l2){

            return l1->val > l2->val;

        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(lambda)>  pq(lambda);

        for(auto & lhead : lists){
            
            while(lhead){
                pq.push(lhead);
                lhead = lhead->next;
            }
        }

        ListNode* ans = new ListNode(0);

        ListNode* newlist = ans;

        while(!pq.empty()){

            newlist->next = pq.top();
            pq.pop();
            newlist = newlist->next;
            newlist->next = nullptr;
        }


        return ans->next;
        
    }
};