#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;



int getValue(const char * &expr) {
    int val;
    sscanf(expr, "%d", &val);
    while (isdigit(*++expr))
        ;
    
    //cout<<val<<endl;

    return val;
}

int evaluate(const char *expr) {
    if (!expr || !*expr) return 0;
    
    int ans = getValue(expr);



    while (*expr == '*' || *expr == '/') {
        if (*expr == '*')
            ans *= getValue(++expr);
        else
            ans /= getValue(++expr);
    }
    
    return *expr =='-' ? ans - evaluate(expr) :  ans + evaluate(expr);
}


int main(int argc, char const *argv[])
{
    
    cout<< evaluate("3 + 1 / 1 *2")<<endl;
}