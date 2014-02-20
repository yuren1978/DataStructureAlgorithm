import java.util.*;

class ThreeSumCloset {
	public int threeSumClosest(int[] num, int target) {
	       
	        if (num==null || num.length<3)
	           return 0;
	        
	        Arrays.sort(num);
	        int output=num[0]+num[1]+num[2];
	        for (int i=0; i<num.length-2;i++){
	            int l=i+1;
	            int r=num.length-1;
	            while(l<r){
	                int sum=num[i]+num[l]+num[r];
	                if (sum==target){
	                  return target;
	                }else if (sum>target){
	                      if (Math.abs(sum-target)<Math.abs(output-target))
	                          output=sum;
	                      r--;
	                }else{
	                    if (Math.abs(sum-target)<Math.abs(output-target))
	                          output=sum;
	                      l++;
	                }
	            }
	        }
	        return output;
	        
	    }
	
	public static void main(String[] args) {
		
	}
}