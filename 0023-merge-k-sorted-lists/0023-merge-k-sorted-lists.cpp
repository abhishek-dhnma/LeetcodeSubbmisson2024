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

    ListNode* mergetwo(ListNode* l1, ListNode* l2){

        if(!l1 && !l2) return nullptr;

        ListNode* ans = new ListNode(0);

        ListNode* newlist = ans;

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

        newlist->next = l1 ? l1 : l2;

        return ans->next;

    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n = lists.size();

        if(n==0) return nullptr;

        if(n==1) return lists[0];

        ListNode* prelist = nullptr;

        for(int i=0; i<n; i++){

            ListNode* mergelist = mergetwo(lists[i], prelist);
            prelist = mergelist;

        }

        return prelist;
        
    }
};