public class Solution {
    public ListNode swapPairs(ListNode head) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ListNode sent = new ListNode(0);
        sent.next = head;
 
        if (head == null) {
            return null;
        }
        ListNode pprev = sent, prev = head, cur = head.next;
        while (cur != null) {
            prev.next =cur.next;
            cur.next = prev;    
            pprev.next = cur;
 
            cur = prev.next;
 
            if (cur != null) {
                pprev = prev;
                prev = cur;
                cur = cur.next;
            }
        }
        return sent.next;
    }
}