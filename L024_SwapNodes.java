/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode swapPairs(ListNode head) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ListNode helper = new ListNode(0);
        helper.next = head;
        ListNode n1 = helper, n2=head;
        
        while(n2!=null && n2.next!=null){
            ListNode temp = n2.next.next; //store third node before changing the position.
            
			//n1 and n2 don't change
            n2.next.next=n1.next;   //let second node point to first node
            n1.next=n2.next;        //let helper node point to second node. 
            n2.next=temp;           //let first node point to the third node
           
            //move pointer forward
            n1=n2;
            n2=n1.next;
        }
        
        return helper.next;
    }
}