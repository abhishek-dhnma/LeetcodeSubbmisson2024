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
    public ListNode mergeKLists(ListNode[] lists) {


        if(lists == null || lists.length == 0) return null;

        
        // priority queue with comparisons
        
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a,b) -> a.val - b.val);
        

        for(ListNode node : lists){
                if(node!=null) pq.add(node);
        }



        ListNode newList = new ListNode();
        ListNode dummy = newList;

        while(!pq.isEmpty()){

            ListNode minNode = pq.poll();

            dummy.next = minNode;
            dummy = dummy.next;

            if(minNode.next != null)
            {
                pq.add(minNode.next);
            }


        }

        return newList.next;

    }
}