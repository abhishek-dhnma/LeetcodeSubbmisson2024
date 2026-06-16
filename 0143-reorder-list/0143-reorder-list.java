/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
         if(head == null ) return;
        if(head.next == null) return;

        // step 1 - find mid value

        ListNode fast = head;
        ListNode slow = head;


        while(fast != null && fast.next != null){

            fast = fast.next.next;
            slow = slow.next;            

        }

        ListNode secondHalf = slow.next;
        slow.next = null;


        // step 2 - reverse the second half
        
        ListNode curr = secondHalf;
        ListNode pre = null;
        ListNode nxt = null;

        while(curr != null){
            nxt = curr.next;
            curr.next = pre;
            pre = curr;
            curr  = nxt;
        }

        ListNode l2 = pre;

        // stapler them 

        ListNode l1 = head;

        while(l1 != null && l2 != null){

            ListNode nxt1 = l1.next;
            ListNode nxt2 = l2.next;
            l1.next = l2;
            l2.next = nxt1;

            l1 = nxt1;
            l2 = nxt2;

        }
        
    }
}