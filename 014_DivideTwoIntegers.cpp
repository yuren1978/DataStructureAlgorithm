
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
using namespace std;

int Divide(int dividend, int divisor) 
{
	
    int quotient = 0;
    bool negative = false; //indicate if the final result is negative

    if (dividend < 0)
    {
        negative = true;
        dividend = -dividend;
    }
    if (divisor < 0)
    {
        negative = !negative; //negative based on dividend else
        divisor = -divisor;
    }

    while(dividend >= divisor)
    {
        int addition = divisor;
        int cur_quotient = 1;

        while(dividend >= (addition + addition))
        {
            //move up bit
            addition += addition;
            cur_quotient <<= 1; // /*equal to*/ cur_quotient += cur_quotient;
        }
		 cout<<cur_quotient<<endl;
        quotient += cur_quotient;
        //prepare for next bit
        dividend -= addition;
    }

    if (negative) quotient = -quotient;

    return quotient;
}

#include <stdio.h>


int main(int argc, char** argv)
{
    int dividend = 100;
	int divisor = 2;
    printf("%d\n", Divide(dividend,divisor));
    return 0;
}