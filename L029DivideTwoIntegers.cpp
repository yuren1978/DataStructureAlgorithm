
/*
**  The idea is to calculate each bit of quotient from high to low.
**  Using addition to move up bit
**
*/

//After test, there is bug for value -2147483648 (the minimus integer);
//as for integer -(-2147483648) is still -2147483648, not 2147483648.
//So we need a larger type which could contains value 2147483648
//typedef long long_int; 

//if the sizeof(long) is equal to sizeof(int) in some system,
//you may need to use long long instead

//typedef long long long_int; 
#include <iostream>
#include <stdio.h>
using namespace std;

int Divide(int dividend, int divisor) 
{
			int sign = 1;
	        if (dividend<0){sign = -sign;}
	        if (divisor<0){sign = -sign;}
	         
	        unsigned long long tmp = abs((long long)dividend);
	        unsigned long long tmp2 = abs((long long)divisor);
	                
	        unsigned long c = 1;
	        while (tmp>tmp2){
	            tmp2 = tmp2<<1;    
	            c = c<<1;
	        }
	
			printf("c is %d and tmp2 is %d\n", c, tmp2);         
	
	        int res = 0;
	        while (tmp>=abs((long long)divisor)){
	            
				while (tmp>=tmp2){//add the result
					 printf("tmp is %d \n", tmp);
	                tmp -= tmp2;
	                res += c;
	            }
				
	            tmp2=tmp2>>1;
	            c=c>>1;    
	        }
	         
	        return sign*res;
	
}	




int main(int argc, char** argv)
{
    int dividend = 15;
	int divisor = 3;
    printf("%d\n", Divide(dividend,divisor));
    return 0;
}