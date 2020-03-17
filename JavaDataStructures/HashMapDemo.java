import java.util.*;

public class HashMapDemo{

    private static void iterateHashMap(){
        HashMap<Integer, String> hmap = new HashMap<Integer, String>();
        //Adding elements to HashMap
        hmap.put(11, "AB");
        hmap.put(2, "CD");
        hmap.put(33, "EF");
        hmap.put(9, "GH");
        hmap.put(3, "IJ");

        //FOR LOOP
        System.out.println("For Loop:");
        for (Map.Entry<Integer, String> me : hmap.entrySet()) {
          System.out.println("Key: "+me.getKey() + " & Value: " + me.getValue());
        }
    }

    public static void main(String args[]) {
       iterateHashMap();
    }
}