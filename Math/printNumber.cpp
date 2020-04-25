#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a =1001;
    int count=0;
    while(a>0){
        int digit=a%10;
        if(digit==1)
            count++;
        a=a/10;    
    }
    cout<<count<<endl;
    return 0;
}
