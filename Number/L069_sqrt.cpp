class Solution {
public:
    bool equal(double a, double b){
        double close=0.000000001;
        return (a-b<close) && (a-b>(0-close)); 
    }

    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x<0) return -1;
        if(x==0) return 0;
        if(x==1) return 1;
        
        double low=0;
        double upper=x<1?1:x;
        
        while(!equal(low, upper)){
            double middle=(low+upper)/2;
            if(equal(middle*middle, x)){
                return middle;
            }
            else if((middle*middle)>x){
                upper=middle;
            }
            else{
                low=middle;
            }
        }
        return (low+upper)/2;
    }
};