import java.util.*;


public class TreeMapDemo {


    private static void iterateTreeMap(){
        TreeMap<Integer, String> treeMap = new TreeMap<Integer, String>();
        //Adding elements to treeMap
        treeMap.put(11, "AB");
        treeMap.put(2, "CD");
        treeMap.put(33, "EF");
        treeMap.put(9, "GH");
        treeMap.put(3, "IJ");

        //FOR LOOP
        System.out.println("For Loop:");
        treeMap.forEach((k,v) -> System.out.println("Key = "+ k + ", Value = " + v)); 

         /* Get values based on key*/
        String var= treeMap.get(2);
        System.out.println("Value at index 2 is: "+var);
    }

    public static void main(String args[]) {
        //addElements();
        //changeElements();
        //iterateElements();
        iterateTreeMap();
    }

}
