class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;

        int first=1; int second=2;
        int third=0;
        int i=3;
        while(i<=n){
        	third=first+second;
        	first=second;
        	second=thrid;
        	i++;
        }
        return third;
    }
};