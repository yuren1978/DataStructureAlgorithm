#include <iostream>
#include <cassert>

using namespace std;


class CException
{
public:
    CException(const char* str) : m_strErr(str) {}
    string GetErrInfo() { return m_strErr; }
private:
    std::string m_strErr;
};

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

    //treat the rest as positive numeric number, so for negative number
    //it is 2^31,  and for positive number it is 2^31
    unsigned int uLimit = bNeg ? 0x7FFFFFFF + 1 : 0x7FFFFFFF;

    // The reson to use unsigned int rather than int is to deal with 2^31
    unsigned int uRes = 0;
    unsigned int uDummy = UINT_MAX/10; // used to judge overflow of unsigned int

    do
    {
        //Deals with illegal character
        if (*pCur < '0' || *pCur > '9')
            throw CException("Illegal character found");

        //Get current digit
        int nDigit = *pCur - '0';

        //Detect the unsigned integer overflow
        if (uRes > uDummy || (uRes == uDummy && nDigit > (UINT_MAX - (UINT_MAX/10)*10)))
            throw CException("Over flow detected");

        //update uRes
        uRes = uRes*10 + nDigit;

        //Overflow situation if uRes isn't overflow
        if (uRes > uLimit)
            throw CException("Over flow detected");

        pCur++;
    }while (*pCur != 0); 

    return bNeg ? (int)(-uRes) : (int)(uRes);
}


int main(int argc, char *argv[]) {
	assert(123==myatoi("123"));
}