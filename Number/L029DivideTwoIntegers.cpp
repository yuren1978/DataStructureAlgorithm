
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
#include <cstdio>
#include <cmath>

using namespace std;

 int divide(int dividend, int divisor) {
        if (divisor == 0) return 0;
       
        unsigned long long a = abs((long long)dividend);
        unsigned long long b = abs((long long)divisor);
        
        
        int result = 0;

 		// for (unsigned long i = 0; b <= a; i++) {
   //              a -= b;
   //              result += 1 << i;
   //              b <<= 1;
   //       }

        while (a >= b) {
            unsigned long c = b;
            cout<<" a " << a << endl;
            for (unsigned long i = 0; c <= a; i++) {
                a -= c;
                result += 1 << i;
                c <<= 1;
            }

        }
        return ((dividend^divisor) >> 31) == 0 ? result : 0 - result;
    }



int main(int argc, char** argv)
{
    int dividend = 5;
	int divisor = 2;
    printf("%d\n", divide(dividend,divisor));
    return 0;
}