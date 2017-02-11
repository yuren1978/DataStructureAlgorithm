import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdIn;


class MaximumGap {


	public static int maximumGap(int[] nums) {
	    if (nums == null || nums.length < 2) {
	        return 0;
	    }
	    
	    // m is the maximal number in nums
	    int m = nums[0];
	    for (int i = 1; i < nums.length; i++) {
	        m = Math.max(m, nums[i]);
	    }
	    
	    int exp = 1; // 1, 10, 100, 1000 ...
	    int R = 10; // 10 digits

	    int[] aux = new int[nums.length];
	    
	    while (m / exp > 0) { // Go through all digits from LSB to MSB
	    	StdOut.println("R : " + R);	

	        int[] count = new int[R];
	        
	        for (int i = 0; i < nums.length; i++) {
	        	
	        	StdOut.println(nums[i] / exp);	


	            count[(nums[i] / exp) % 10]++;
	        }
	        
	        for (int i = 1; i < count.length; i++) {
	            count[i] += count[i - 1];
	        }
	        
	        for (int i = nums.length - 1; i >= 0; i--) {
	            aux[--count[(nums[i] / exp) % 10]] = nums[i];
	        }
	        
	        for (int i = 0; i < nums.length; i++) {
	            nums[i] = aux[i];
	        }
	        exp *= 10;
	    }
	    
	    int max = 0;
	    for (int i = 1; i < aux.length; i++) {
	        max = Math.max(max, aux[i] - aux[i - 1]);
	    }
	     
	    return max;
	}


	public static void main(String[] args) {
			StdOut.println("Maximum Gap");
			int[] numbers = new int[] {123, 121, 231};
			int maxGap=maximumGap(numbers);
			StdOut.println(maxGap);
		
	}
}
