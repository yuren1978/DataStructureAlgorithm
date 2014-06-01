//http://dl.dropbox.com/u/19732851/LeetCode/ReadMe.html
#include <cstdio>
#include <cassert>
#include <iostream>

using namespace std;

const int skipSpace(const char* s){
    int size=0;
    while(' '==*(s+size))
        size++;
    return size;
}

const int skipSign(const char* s){
    int size=0;
    if('+'==*s || '-'==*s )
        size++;
    return size;
}

const int skipDigit(const char* s){
    int size=0;
    while(*(s+size)>='0' && *(s+size)<='9')
        size++;
    return size;
}




bool isNumber(const char *s) 
{
    const char* p=s;
    if(NULL==p) return false;

    p += skipSpace(p);
    if('\0'==p) return false;

    p += skipSign(p);
    if('\0'==p) return false;

    int n1=skipDigit(p);
    p +=n1;

    if('.'==*p)
        p++;

    int n2=skipDigit(p);
    p +=n2;

    if(n1==0 && n2==0) return false;

    if('e'==*p || 'E'==*p){
        p++;
        p +=skipSign(p);
        int n3=skipDigit(p);
        if(0==n3) return false;

        p +=n3;
    }

    p += skipSpace(p);

    return *p=='\0';
}


int main(int argc, char** argv)
{

    assert(true==isNumber("0"));
    assert(true==isNumber(" 0.1"));
    assert(false==isNumber("abc"));
    assert(false==isNumber("1 a"));
    assert(true==isNumber("2e10"));
	return 0;
}