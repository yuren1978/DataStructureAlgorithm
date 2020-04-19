import java.util.*;


public class LinkListDemo {

    private static void iterateQueueElements() {
        Queue<String> q=new LinkedList<String>();

        //Adding elements to the Linked list
        q.add("Steve");
        q.add("Carl");
        q.add("Raj");
   
        for(String str:q) { 
            System.out.println(str);  
        }  

        System.out.println("Elements in Queue:"+q);

        /*
        * We can remove element from Queue using remove() method,
        * this would remove the first element from the Queue 
        */
        System.out.println("Removed element: "+q.remove());
            
        /*
        * element() method - this returns the head of the
        * Queue. Head is the first element of Queue
        */
        System.out.println("Head: "+q.element());
            
        /*
        * poll() method - this removes and returns the 
        * head of the Queue. Returns null if the Queue is empty
        */
        System.out.println("poll(): "+q.poll());
            
        /*
        * peek() method - it works same as element() method,
        * however it returns null if the Queue is empty
        */
        System.out.println("peek(): "+q.peek());
    }

    private static void iterateElements() {
        LinkedList<String> list=new LinkedList<String>();

        //Adding elements to the Linked list
        list.add("Steve");
        list.add("Carl");
        list.add("Raj");
   
        //Adding an element to the first position
        list.addFirst("Negan");
   
        //Adding an element to the last position
        list.addLast("Rick");
   
        //Adding an element to the 3rd position
        list.add(2, "Glenn");

        for(String str:list) { 
            System.out.println(str);  
        }  
    }


    public static void main(String args[]) {
        //addElements();
        //changeElements();
        //iterateElements();
        iterateQueueElements();
    }
}
