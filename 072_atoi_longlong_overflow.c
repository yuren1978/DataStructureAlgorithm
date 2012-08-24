#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

typedef enum {false, true} bool;

int g_ErrorCode=0;

int myatoi(const char* p)
{
    assert(p);

    //Judge signal
    bool bNeg = false;
    const char* pCur = p;
    if(*pCur == '-' || *pCur == '+')
    {
        if (*pCur++ == '-') 
            bNeg = true;
    }

    long long dummy = INT_MIN;
    //can't directly use -(INT_MIN) because of precompile treat -(INT_MIN)
    //as 32 bit integer which will cause overflow
    long long limit = bNeg ? -(dummy) : INT_MAX;
    long long res = 0;

    do
    {
        //Deals with illegal character
        if (*pCur < '0' || *pCur > '9'){
			g_ErrorCode=1;
			return 0;
		}	
            

        //Get current digit
        int nDigit = *pCur - '0';

        //update uRes
        res = res*10 + nDigit;

        //Overflow situation if uRes isn't overflow
        if (res > limit){
			g_ErrorCode=2;
			return 0;
		}	

        pCur++;
    }while (*pCur != 0); // WTF stupid error again, do while not while you  mother fucker!!!

    return bNeg ? (int)(-res) : (int)(res);
}

int main(int argc, char *argv[]) {
	assert(myatoi("-302")==-302);
}