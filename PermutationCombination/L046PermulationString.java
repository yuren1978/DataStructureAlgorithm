//http://www.ardendertat.com/2011/10/28/programming-interview-questions-11-all-permutations-of-string/
import java.util.*;

class L046PermulationString {
	
	
	private static void permute2Recursive(String prefix, String str) {
		 
	    int n = str.length();
	    if (n == 0) System.out.println(prefix);
	    else {
	        for (int i = 0; i < n; i++)
	           permute2Recursive(prefix + str.charAt(i), str.substring(0, i) + str.substring(i+1, n));
	    }
	}
	
	public  static void permute2(String str) { 
	    permute2Recursive("", str); 
	}
	
	private static void permuateInteger(int[] num , int level,ArrayList<ArrayList<Integer>> permArray){
		if(level==num.length){
			ArrayList<Integer> array=new ArrayList<Integer>();
			for (int i=0; i<num.length;i++) {
				array.add(num[i]);
			}
			permArray.add(array);
			return;
		}		
		for (int i=level;i<num.length; ++i) {
			swapInteger(num, i, level);
			permuateInteger(num, level+1, permArray);
			swapInteger(num, level, i);
		}
	}
	
	 public ArrayList<ArrayList<Integer>> permute(int[] num) {
	        // Start typing your Java solution below
	        // DO NOT write main() function
		ArrayList<ArrayList<Integer>> permuatedArray=new ArrayList<ArrayList<Integer>>();	
	    permuateInteger(num, 0,permuatedArray)  ;
		return permuatedArray;
	 }
	
	private static void permute ( char[] perm, int level) {
		System.out.print("level is "+level+"  ");
		printArray(perm);
	  if ( level == perm.length )
	    System.out.println( new String( perm ) );

	  //permute( perm, level + 1 );
	  for ( int i = level; i < perm.length; i++ ) {
	    //if ( level != i ) 
	      swap( perm, level, i );
	    permute( perm, level + 1 );
	    //if ( level != i ) 
	      swap( perm, level, i );
	  }
	}

	private static void swapInteger(int[] arr, int i, int j) {
		int c=arr[i];
		arr[i]=arr[j];
		arr[j]=c;
	}

	private static void swap(char[] arr, int i, int j) {
		char c=arr[i];
		arr[i]=arr[j];
		arr[j]=c;
	}
	
	private static void printArray(char[] perm){
		System.out.print("Array is ");
		for ( int i = 0; i < perm.length; i++ ){
			System.out.print(perm[i]);
		}
		System.out.println();
	}
	
	public static void main(String[] args) {
		//printArray(new char[]{'a','b','c'});
		permute( new char[]{'a','b','c'}, 0 );
		//permute2("abc");
	}
}