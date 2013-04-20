class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x==0){
            if(n==0) {
                 return 1;
            }               
            else{
                 return 0;
            } 
        }
        
        if(n==0){
            return 1;
        }
        
        bool negative=false;
        if(n<0){
            negative=true;
            n=-n;            
        }
        
        double base=x;
        double result=1;
        while(n>0){
            if(n & 1){
                result=result*base;
            }
            
            base=base*base;
            n=n>>1;
        }
        return negative? 1/result : result;
    }
};