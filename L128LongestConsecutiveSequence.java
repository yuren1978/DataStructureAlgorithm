import java.util.*;
import java.lang.Math;

class L128LongestConsecutiveSequence {
	
	static int getCounts(Set<Integer> hs, int v, boolean asc){
		int count=0;
		while (hs.contains(v)) {
			hs.remove(v);
			count++;
			if(asc) 
				v++;
			else
				v--;	
		}
		return count;
	}
	
	static void printSet(Set<Integer> hs){
		System.out.println("print set:");
		for (int v: hs) {
			System.out.println(v);
		}	
	}
	
	public static void main(String[] args) {
		int[] num={100, 4, 200, 1, 3, 2, 6, 50, 7, 3};
		Set<Integer> hs=new HashSet<Integer>();
		for (int v:num) {
			hs.add(v);
		}  
		
		printSet(hs);
	
		int ans=0;
		for (int v:num) {
			
			if(hs.contains(v)){
				//System.out.println(getCounts(hs,v,false));
				System.out.println(v+": "+ (getCounts(hs,v,false)));
				//System.out.println(v+": "+ (getCounts(hs,v,false)+getCounts(hs, v+1, true)));
				//ans=Math.max(ans, getCounts(hs,v,false)+getCounts(hs, v+1, true));
			}
		}
		
		System.out.println("Answer is : "+ ans);
	}
}