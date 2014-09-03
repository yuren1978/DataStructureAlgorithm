public class Solution {
    public String multiply(String a, String b) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int m = a.length();
        int n = b.length();
        int[] rl = new int[m + n];
        for(int i = n - 1; i >= 0; i--){
            int carry = 0;
            for(int j = m - 1; j >= 0; j--){
                int tmp = (b.charAt(i) - '0') * (a.charAt(j) - '0') + carry + rl[i + j + 1];
                rl[i + j + 1] = tmp % 10;
                carry = tmp / 10;
            }
            rl[i] = carry;
        }
        String ans = "";
        for(int x : rl)
            if(x != 0 || !ans.isEmpty()) ans += x;
        return (ans.isEmpty()) ? "0" : ans;
    }
}