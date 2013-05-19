public class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(k<=1 || head==null || head.next==null) return head;
        
        ListNode prev = new ListNode(0);
        prev.next = head;
        head = prev;
        
        ListNode cur=prev.next;

        while(cur!=null){
            int counter = k;
            while(cur!=null && counter>1){
                cur = cur.next;
                counter--;
            }
            
            if(cur!=null){
                cur=prev.next;
                counter=k;
                while(counter>1){
                    ListNode temp = cur.next;
                    cur.next=temp.next;
                    temp.next=prev.next;
                    prev.next=temp;
                    counter--;
                }
                prev = cur;
                cur = prev.next;
            }
        }
        
        return head.next;
    }
}