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

       vector<int> temp;


       while(head != NULL){
        temp.push_back(head->val);
        head = head->next;
       }

       for(auto & v : temp){
        cout << v;
       }
    int n = temp.size();
        for(int i= n-1; i >= 0; i--){

           sum += (temp[i] * pow(2, n - 1 - i));
        }

        return sum;


        
    }
};