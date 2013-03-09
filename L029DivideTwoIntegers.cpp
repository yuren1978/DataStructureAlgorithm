
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
	  long dividend_long=dividend;
	    long divisor_long=divisor;
	    bool isNegative=false;
	   
	    if(dividend_long<0)
	    {
	        isNegative=true;
	        dividend_long=-dividend_long;
	    }
	   
	    if(divisor_long<0)
	    {
	        isNegative=!isNegative;
	        divisor_long=-divisor_long;
	    }
	   
	    int quotient=0;       
	    while(dividend_long>=divisor_long)
	    {
	        long sum=divisor_long;
	        int digit=1;
	        while((sum+sum)<=dividend_long)
	        {
	            sum+=sum;
	            digit<<=1;
	        }
	        quotient+=digit;
	        dividend_long-=sum;
	    }
	   
	    if(isNegative)
	        quotient=-quotient;
	   
	    return quotient; 
}	




int main(int argc, char** argv)
{
    int dividend = 2147483647;
	int divisor = 2;
    printf("%d\n", Divide(dividend,divisor));
    return 0;
}