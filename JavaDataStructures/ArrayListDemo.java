import java.util.*;


public class ArrayListDemo {

    public static void addElements(){
        ArrayList<String> sampleList=new ArrayList<String>();  
        sampleList.add("Steve");
        sampleList.add("Tim");
        sampleList.add("Lucy");
        sampleList.add("Pat");
        sampleList.add("Angela");
        sampleList.add("Tom");
    
        //displaying elements
        System.out.println(sampleList);
    
        //Adding "Steve" at the fourth position
        sampleList.add(3, "Steve");
    
        //displaying elements
        System.out.println(sampleList);
    }

    public static void changeElements(){
        ArrayList<String> names = new ArrayList<String>();
        names.add("Jim");
        names.add("Jack");
        names.add("Ajeet");
        names.add("Chaitanya");
        names.set(0, "Lucy");
        System.out.println(names);
    }

    public static void iterateElements(){
        ArrayList<String> nameStrings=new ArrayList<String>();  
        nameStrings.add("George Sun");  
        nameStrings.add("Crystal Dong");  
        //iterating ArrayList
        for(String str:nameStrings) { 
            System.out.println(str);  
        }  
    }

    public static void main(String args[]) {
        //addElements();
        //changeElements();
        iterateElements();
    }
}